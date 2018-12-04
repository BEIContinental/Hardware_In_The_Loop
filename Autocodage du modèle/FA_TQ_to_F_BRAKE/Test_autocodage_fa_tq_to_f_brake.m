% - - - - - TEST AUTOCODAGE FA_TQ_to_F_BRAKE - - - - - %
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

FA_PLA_F_BRAKE = load('OUTPUTS\FA_PLA_F_BRAKE.txt');

% Sortie codee %
% On cree une structure dans laquelle on charge les fichiers de sortie
% issus de l'autocodage

FA_PLA_F_BRAKE_code = load('OUTPUTS_CODE\FA_PLA_F_BRAKE_code.txt');

% Affichage - Comparaison %

figure
plot(t, FA_PLA_F_BRAKE)
hold on
plot(t, FA_PLA_F_BRAKE_code)
title('FA\_PLA\_F\_BRAKE')
legend('simulation','autocodage')

figure
plot(t, abs(FA_PLA_F_BRAKE-FA_PLA_F_BRAKE_code)*100/max(abs(FA_PLA_F_BRAKE)))
title('Erreur FA\_PLA\_F\_BRAKE')