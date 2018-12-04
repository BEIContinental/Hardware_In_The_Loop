% - - - - - TEST AUTOCODAGE RA_TQ_to_F_BRAKE - - - - - %
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

RA_PLA_F_BRAKE = load('OUTPUTS\RA_PLA_F_BRAKE.txt');

% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

RA_PLA_F_BRAKE_code = load('OUTPUTS_CODE\RA_PLA_F_BRAKE_code.txt');

% Affichage - Comparaison %

figure
subplot(1,2,1)
plot(t,RA_PLA_F_BRAKE)
hold on
plot(t,RA_PLA_F_BRAKE_code)
legend('simulation','autocodage')

subplot(1,2,2)
plot(t,abs(RA_PLA_F_BRAKE - RA_PLA_F_BRAKE_code)*100/max(abs(RA_PLA_F_BRAKE)))
title('Erreur RA\_PLA\_F\_BRAKE')
