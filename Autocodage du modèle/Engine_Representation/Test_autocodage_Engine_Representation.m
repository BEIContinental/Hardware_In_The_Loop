% - - - - - TEST AUTOCODAGE Engine_Representation - - - - - %
% - - - - - IL FAUT AVOIR CREE LES FICHIERS OUTPUTS_code - - - - - %
% - - - - - Ici on est en 200s de simu avec un pas de 0.01 - - - - - %

close all
clear all

tfin = 200;
pas = 0.01;

t = 0:pas:tfin;

% Sortie de base %
% On cree une structure dans laquelle on charge les fichiers de sortie de
% la simulation 

OB_ER = struct;

OB_ER.RA_TQ_ME = load('OUTPUTS_SIMULINK\RA_TQ_ME.txt');
OB_ER.RA_TQ_MIN_ME = load('OUTPUTS_SIMULINK\RA_TQ_MIN_ME.txt');
OB_ER.RA_TQ_MAX_ME = load('OUTPUTS_SIMULINK\RA_TQ_MAX_ME.txt');

% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

OB_ER_code = struct;

OB_ER_code.RA_TQ_ME_code = load('OUTPUTS_CODE\RA_TQ_ME_code.txt');
OB_ER_code.RA_TQ_MIN_ME_code = load('OUTPUTS_CODE\RA_TQ_MIN_ME_code.txt');
OB_ER_code.RA_TQ_MAX_ME_code = load('OUTPUTS_CODE\RA_TQ_MAX_ME_code.txt');

% Affichage - Comparaison %

figure
plot(t,OB_ER.RA_TQ_ME)
hold on
plot(t,OB_ER_code.RA_TQ_ME_code)
legend('simulation','autocodage')

figure
plot(t,OB_ER.RA_TQ_MIN_ME)
hold on
plot(t,OB_ER_code.RA_TQ_MIN_ME_code)
legend('simulation','autocodage')

figure
plot(t,OB_ER.RA_TQ_MAX_ME)
hold on
plot(t,OB_ER_code.RA_TQ_MAX_ME_code)
legend('simulation','autocodage')

figure
subplot(1,3,1)
plot(t,abs(OB_ER.RA_TQ_ME - OB_ER_code.RA_TQ_ME_code)*100/max(abs(OB_ER.RA_TQ_ME)))
title('Erreur RA\_TQ\_ME')
subplot(1,3,2)
plot(t,abs(OB_ER.RA_TQ_MIN_ME - OB_ER_code.RA_TQ_MIN_ME_code)*100/max(abs(OB_ER.RA_TQ_MIN_ME)))
title('Erreur RA\_TQ\_MIN\_ME')
subplot(1,3,3)
plot(t,abs(OB_ER.RA_TQ_MAX_ME - OB_ER_code.RA_TQ_MAX_ME_code)/max(abs(OB_ER.RA_TQ_MAX_ME)))
title('Erreur RA\_TQ\_MAX\_ME')
