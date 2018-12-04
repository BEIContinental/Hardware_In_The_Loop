% - - - - - TEST AUTOCODAGE CLUTCH - - - - - %
% - - - - - IL FAUT AVOIR CREE LES FICHIERS OUTPUTS_code - - - - - %
% - - - - - Ici ou est en 200s de simu avec un pas de 0.01 - - - - - %

close all
clear all

tfin = 200;
pas = 0.01;

t = 0:pas:tfin;

% Sortie de base %
% On cree une structure dans laquelle on charge les fichiers de sortie de
% la simulation 

OB_CLU = struct;

OB_CLU.FA_N_ICE = load('OUTPUTS\FA_N_ICE.txt');
OB_CLU.FA_TQ_CLU = load('OUTPUTS\FA_TQ_CLU.txt');
OB_CLU.FA_CLU_STUCK = load('OUTPUTS\FA_CLU_STUCK.txt');

% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

OB_CLU_code = struct;

OB_CLU_code.FA_N_ICE_code = load('OUTPUTS_CODE\FA_N_ICE_code.txt');
OB_CLU_code.FA_TQ_CLU_code = load('OUTPUTS_CODE\FA_TQ_CLU_code.txt');
OB_CLU_code.FA_CLU_STUCK_code = load('OUTPUTS_CODE\FA_CLU_STUCK_code.txt');

% Affichage - Comparaison %

figure
plot(t,OB_CLU.FA_N_ICE)
hold on
plot(t,OB_CLU_code.FA_N_ICE_code)
title('FA_N_ICE')
legend('simulation','autocodage')

figure
plot(t,OB_CLU.FA_TQ_CLU)
hold on
plot(t,OB_CLU_code.FA_TQ_CLU_code)
title('FA_TQ_CLU')
legend('simulation','autocodage')

figure
plot(t,OB_CLU.FA_CLU_STUCK)
hold on
plot(t,OB_CLU_code.FA_CLU_STUCK_code)
title('FA_CLU_STUCK')
legend('simulation','autocodage')

figure
subplot(1,3,1)
plot(t,abs(OB_CLU.FA_N_ICE-OB_CLU_code.FA_N_ICE_code)*100/max(abs(OB_CLU.FA_N_ICE)))
title('Erreur FA\_N\_ICE')
subplot(1,3,2)
plot(t,abs(OB_CLU.FA_TQ_CLU-OB_CLU_code.FA_TQ_CLU_code)*100/max(abs(OB_CLU.FA_TQ_CLU)))
title('Erreur FA\_TQ\_CLU')
subplot(1,3,3)
plot(t,abs(OB_CLU.FA_CLU_STUCK-OB_CLU_code.FA_CLU_STUCK_code)/max(abs(OB_CLU.FA_CLU_STUCK)))
title('Erreur FA\_CLU\_STUCK')
