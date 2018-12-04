% - - - - - TEST AUTOCODAGE ICE_control - - - - - %
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

OB_ICE_CTRL = struct;

OB_ICE_CTRL.FA_ICE_STATE = load('OUTPUTS\FA_ICE_STATE.txt');
OB_ICE_CTRL.FA_ICE_TQ_SP = load('OUTPUTS\FA_ICE_TQ_SP.txt');
OB_ICE_CTRL.FA_STARTER_REQUEST = load('OUTPUTS\FA_STARTER_REQUEST.txt');
OB_ICE_CTRL.FA_TQ_MAX_ICE = load('OUTPUTS\FA_TQ_MAX_ICE.txt');
OB_ICE_CTRL.FA_TQ_MIN_ICE = load('OUTPUTS\FA_TQ_MIN_ICE.txt');
 
% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

OB_ICE_CTRL_code =struct;

OB_ICE_CTRL_code.FA_ICE_STATE_code = load('OUTPUTS_CODE\FA_ICE_STATE_code.txt');
OB_ICE_CTRL_code.FA_ICE_TQ_SP_code = load('OUTPUTS_CODE\FA_ICE_TQ_SP_code.txt');
OB_ICE_CTRL_code.FA_STARTER_REQUEST_code = load('OUTPUTS_CODE\FA_STARTER_REQUEST_code.txt');
OB_ICE_CTRL_code.FA_TQ_MAX_ICE_code = load('OUTPUTS_CODE\FA_TQ_MAX_ICE_code.txt');
OB_ICE_CTRL_code.FA_TQ_MIN_ICE_code = load('OUTPUTS_CODE\FA_TQ_MIN_ICE_code.txt');

% Affichage - Comparaison %

figure
plot(OB_ICE_CTRL.FA_ICE_STATE)
hold on
plot(OB_ICE_CTRL_code.FA_ICE_STATE_code)
title('FA\_ICE\_STATE')
legend('simulation','autocodage')

figure 
plot(t,OB_ICE_CTRL.FA_ICE_TQ_SP)
hold on
plot(t,OB_ICE_CTRL_code.FA_ICE_TQ_SP_code)
title('FA\_TQ\_SP')
legend('simulation','autocodage')

figure
plot(t,OB_ICE_CTRL.FA_STARTER_REQUEST)
hold on
plot(t,OB_ICE_CTRL_code.FA_STARTER_REQUEST_code)
title('FA\_STARTER\_REQUEST')
legend('simulation','autocodage')

figure
plot(t,OB_ICE_CTRL.FA_TQ_MAX_ICE)
hold on
plot(t,OB_ICE_CTRL_code.FA_TQ_MAX_ICE_code)
title('FA\_TQ\_MAX\_ICE')
legend('simulation','autocodage')

figure
plot(t,OB_ICE_CTRL.FA_TQ_MIN_ICE)
hold on
plot(t,OB_ICE_CTRL_code.FA_TQ_MIN_ICE_code)
title('FA\_TQ\_MIN\_ICE')
legend('simulations','autocodage')

figure
subplot(2,3,1)
plot(t,abs(OB_ICE_CTRL.FA_ICE_STATE-OB_ICE_CTRL_code.FA_ICE_STATE_code)*100/max(abs(OB_ICE_CTRL.FA_ICE_STATE)))
title('Erreur FA\_ICE\_STATE')
subplot(2,3,2)
plot(t,abs(OB_ICE_CTRL.FA_ICE_TQ_SP-OB_ICE_CTRL_code.FA_ICE_TQ_SP_code)*100/max(abs(OB_ICE_CTRL.FA_ICE_TQ_SP)))
title('Erreur FA\_ICE\_TQ\_SP')
subplot(2,3,3)
plot(t,abs(OB_ICE_CTRL.FA_STARTER_REQUEST-OB_ICE_CTRL_code.FA_STARTER_REQUEST_code)*100/max(abs(OB_ICE_CTRL.FA_STARTER_REQUEST)))
title('Erreur FA_STARTER_REQUEST')
subplot(2,3,4)
plot(t,abs(OB_ICE_CTRL.FA_TQ_MAX_ICE-OB_ICE_CTRL_code.FA_TQ_MAX_ICE_code)*100/max(abs(OB_ICE_CTRL.FA_TQ_MAX_ICE)))
title('Erreur FA\_TQ\_MAX')
subplot(2,3,5)
plot(t,abs(OB_ICE_CTRL.FA_TQ_MIN_ICE-OB_ICE_CTRL_code.FA_TQ_MIN_ICE_code)*100/max(abs(OB_ICE_CTRL.FA_TQ_MIN_ICE)))
title('Erreur FA\_TQ\_MAX')
        