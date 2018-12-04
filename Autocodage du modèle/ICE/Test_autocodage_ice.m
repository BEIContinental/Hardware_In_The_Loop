% - - - - - TEST AUTOCODAGE ICE - - - - - %
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

OB_ICE = struct;

OB_ICE.FA_GAS_CONSUMPTION = load('OUTPUTS\FA_GAS_CONSUMPTION.txt');
OB_ICE.FA_TQ_ICE = load('OUTPUTS\FA_TQ_ICE.txt');
OB_ICE.FA_TQ_STARTER = load('OUTPUTS\FA_TQ_STARTER.txt');

% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

OB_ICE_code = struct;

OB_ICE_code.FA_GAS_CONSUMPTION_code = load('OUTPUTS_CODE\FA_GAS_CONSUMPTION_code.txt');
OB_ICE_code.FA_TQ_ICE_code = load('OUTPUTS_CODE\FA_TQ_ICE_code.txt');
OB_ICE_code.FA_TQ_STARTER_code = load('OUTPUTS_CODE\FA_TQ_STARTER_code.txt');

% Affichage - Comparaison %

figure
plot(t,OB_ICE.FA_GAS_CONSUMPTION)
hold on
plot(t,OB_ICE_code.FA_GAS_CONSUMPTION_code)
title('FA_GAS_CONSUMPTION')
legend('simulation','autocodage')

figure
plot(t,OB_ICE.FA_TQ_ICE)
hold on
plot(t,OB_ICE_code.FA_TQ_ICE_code)
title('FA_TQ_ICE')
legend('simulation','autocodage')

figure
plot(t,OB_ICE.FA_TQ_STARTER)
hold on
plot(t,OB_ICE_code.FA_TQ_STARTER_code)
title('FA_TQ_STARTER')
legend('simulation','autocodage')

figure
subplot(1,3,1)
plot(t,abs(OB_ICE.FA_TQ_ICE-OB_ICE_code.FA_TQ_ICE_code)*100/max(abs(OB_ICE.FA_TQ_ICE)))
title('Erreur FA\_TQ\_ICE')
subplot(1,3,2)
plot(t,abs(OB_ICE.FA_GAS_CONSUMPTION-OB_ICE_code.FA_GAS_CONSUMPTION_code)*100/max(abs(OB_ICE.FA_GAS_CONSUMPTION)))
title('Erreur FA\_GAS\_CONSUMPTION')
subplot(1,3,3)
plot(t,abs(OB_ICE.FA_TQ_STARTER-OB_ICE_code.FA_TQ_STARTER_code)*100/max(abs(OB_ICE.FA_TQ_STARTER)))
title('Erreur FA\_TQ\_STARTER')
