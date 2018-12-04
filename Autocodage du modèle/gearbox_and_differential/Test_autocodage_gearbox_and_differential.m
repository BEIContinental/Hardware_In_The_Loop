% - - - - - TEST AUTOCODAGE gearbox_and_differential - - - - - %
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

OB_GAD = struct;

OB_GAD.FA_N_BGX = load('OUTPUTS\FA_N_GBX.txt');
OB_GAD.FA_TQ = load('OUTPUTS\FA_TQ.txt');
OB_GAD.FA_TQ_MAX = load('OUTPUTS\FA_TQ_MAX.txt');
OB_GAD.FA_TQ_MIN = load('OUTPUTS\FA_TQ_MIN.txt');

% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

OB_GAD_code = struct;

OB_GAD_code.FA_N_BGX_code = load('OUTPUTS_CODE\FA_N_GBX_code.txt');
OB_GAD_code.FA_TQ_code = load('OUTPUTS_CODE\FA_TQ_code.txt');
OB_GAD_code.FA_TQ_MAX_code = load('OUTPUTS_CODE\FA_TQ_MAX_code.txt');
OB_GAD_code.FA_TQ_MIN_code = load('OUTPUTS_CODE\FA_TQ_MIN_code.txt');

% Affichage - Comparaison %

figure
plot(t,OB_GAD.FA_N_BGX)
hold on
plot(t,OB_GAD_code.FA_N_BGX_code)
title('FA\_N\_BGX')
legend('simulation','autocodage')

figure
plot(t,OB_GAD.FA_TQ)
hold on
plot(t,OB_GAD_code.FA_TQ_code)
title('FA\_TQ')
legend('simulation','autocodage')

figure
plot(t,OB_GAD.FA_TQ_MAX)
hold on
plot(t,OB_GAD_code.FA_TQ_MAX_code)
title('FA\_TQ\_MAX')
legend('simulation','autocodage')

figure
plot(t,OB_GAD.FA_TQ_MIN)
hold on
plot(t,OB_GAD_code.FA_TQ_MIN_code)
title('FA\_TQ\_MIN')
legend('simulation','autocodage')
