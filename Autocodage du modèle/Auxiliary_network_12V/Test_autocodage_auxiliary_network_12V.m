% - - - - - TEST AUTOCODAGE Auxiliary_network_12V - - - - - %
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

SYSE_AUX_CURRENT = load('OUTPUTS\SYSE_AUX_CURRENT.txt');
    
% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

SYSE_AUX_CURRENT_code = load('OUTPUTS_CODE\SYSE_AUX_CURRENT_code.txt');

% Affichage - Comparaison %

figure
plot(t, SYSE_AUX_CURRENT)
hold on
plot(t, SYSE_AUX_CURRENT_code)
title('SYSE\_AUX\_CURRENT')
legend('simulation','autocodage')

figure
plot(t, abs(SYSE_AUX_CURRENT-SYSE_AUX_CURRENT_code)*100/max(abs(SYSE_AUX_CURRENT)))
title('Erreur SYSE\_AUX\_CURRENT')

