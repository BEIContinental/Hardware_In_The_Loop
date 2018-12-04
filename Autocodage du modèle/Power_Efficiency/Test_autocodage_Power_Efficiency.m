% - - - - - TEST AUTOCODAGE Power_Efficiency - - - - - %
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


RA_EM_CURRENT = load('OUTPUTS_SIMULINK\RA_EM_CURRENT.txt');

% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

RA_EM_CURRENT_code = load('OUTPUTS_CODE\RA_EM_CURRENT_code.txt');

% Affichage - Comparaison %

figure
plot(t,RA_EM_CURRENT)
hold on
plot(t,RA_EM_CURRENT_code)
legend('simulation','autocodage')

figure
plot(t,abs(RA_EM_CURRENT - RA_EM_CURRENT_code)*100/max(abs(RA_EM_CURRENT)))
title('Erreur RA\_EM\_CURRENT')

