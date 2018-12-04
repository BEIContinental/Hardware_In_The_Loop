% - - - - - TEST AUTOCODAGE electrical_system_supervision  - - - - - %
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

OB_SS = struct;

OB_SS.SYSE_TQ_MAX = load('OUTPUTS\SYSE_TQ_MAX.txt');
OB_SS.SYSE_TQ_MIN = load('OUTPUTS\SYSE_TQ_MIN.txt');

% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

OB_SS_code = struct;

OB_SS_code.SYSE_TQ_MAX_code = load('OUTPUTS_CODE\SYSE_TQ_MAX_code.txt');
OB_SS_code.SYSE_TQ_MIN_code = load('OUTPUTS_CODE\SYSE_TQ_MIN_code.txt');

% Affichage - Comparaison %

figure
plot(t,OB_SS.SYSE_TQ_MAX)
hold on
plot(t,OB_SS_code.SYSE_TQ_MAX_code)
title('SYSE\_TQ\_MAX')
legend('simulation','autocodage')

figure
plot(t,OB_SS.SYSE_TQ_MIN)
hold on
plot(t,OB_SS_code.SYSE_TQ_MIN_code)
title('SYSE\_TQ\_MIN')
legend('simulation','autocodage')

figure
plot(t, abs(OB_SS.SYSE_TQ_MAX-OB_SS_code.SYSE_TQ_MAX_code)*100/max(abs(OB_SS.SYSE_TQ_MAX)))
title('Erreur SYSE\_TQ\_MAX')
legend('simulation','autocodage')

figure
plot(t, abs(OB_SS.SYSE_TQ_MIN-OB_SS_code.SYSE_TQ_MIN_code)*100/max(abs(OB_SS.SYSE_TQ_MIN)))
title('Erreur SYSE\_TQ\_MIN')