% - - - - - TEST AUTOCODAGE Differential - - - - - %
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

OB_DIFF = struct;

OB_DIFF.RA_TQ = load('OUTPUTS\RA_TQ.txt');
OB_DIFF.RA_TQ_MIN = load('OUTPUTS\RA_TQ_MIN.txt');
OB_DIFF.RA_TQ_MAX = load('OUTPUTS\RA_TQ_MAX.txt');
OB_DIFF.RA_N_EM = load('OUTPUTS\RA_N_EM.txt');
% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

OB_DIFF_code = struct;

OB_DIFF_code.RA_TQ_code = load('OUTPUTS_CODE\RA_TQ_code.txt');
OB_DIFF_code.RA_TQ_MIN_code = load('OUTPUTS_CODE\RA_TQ_MIN_code.txt');
OB_DIFF_code.RA_TQ_MAX_code = load('OUTPUTS_CODE\RA_TQ_MAX_code.txt');
OB_DIFF_code.RA_N_EM_code = load('OUTPUTS_CODE\RA_N_EM_code.txt');
% Affichage - Comparaison %

figure
plot(t,OB_DIFF.RA_TQ)
hold on
plot(t,OB_DIFF_code.RA_TQ_code)
legend('simulation','autocodage')

figure
plot(t,OB_DIFF.RA_TQ_MIN)
hold on
plot(t,OB_DIFF_code.RA_TQ_MIN_code)
legend('simulation','autocodage')

figure
plot(t,OB_DIFF.RA_TQ_MAX)
hold on
plot(t,OB_DIFF_code.RA_TQ_MAX_code)
legend('simulation','autocodage')

figure
plot(t,OB_DIFF.RA_N_EM)
hold on
plot(t,OB_DIFF_code.RA_N_EM_code)
legend('simulation','autocodage')

figure
subplot(1,4,1)
plot(t,abs(OB_DIFF.RA_TQ - OB_DIFF_code.RA_TQ_code)*100/max(abs(OB_DIFF.RA_TQ)))
title('Erreur RA\_TQ')
subplot(1,4,2)
plot(t,abs(OB_DIFF.RA_TQ_MIN - OB_DIFF_code.RA_TQ_MIN_code)*100/max(abs(OB_DIFF.RA_TQ_MIN)))
title('Erreur RA\_TQ\_MIN')
subplot(1,4,3)
plot(t,abs(OB_DIFF.RA_TQ_MAX - OB_DIFF_code.RA_TQ_MAX_code)/max(abs(OB_DIFF.RA_TQ_MAX)))
title('Erreur RA\_TQ\_MAX')
subplot(1,4,4)
plot(t,abs(OB_DIFF.RA_N_EM - OB_DIFF_code.RA_N_EM_code)/max(abs(OB_DIFF.RA_N_EM)))
title('Erreur RA\_N\_EM')
