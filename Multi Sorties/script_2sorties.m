clear all
close all 
clc 

%%%%%%%%%%%% seance 3 %%%%%%%%%%%%%%%

Te=1e-4; 
Ka=0.1;
Kb=0.15;
Tf=0.1;
Kd=10;
load('u.txt');
load('y_sortie1.txt');
load('y_sortie2.txt');


t=[0:Te:0.0149]';



sim('test_seance4_2sorties');

figure;
subplot(1,2,1)
plot(t,y_sortie1,'bo');
hold on
plot(t,y_sim1,'r+');
hold off
grid on
subplot(1,2,2)
plot(t,y_sortie2,'bo');
hold on
plot(t,y_sim2,'r+');
hold off
grid on
title('comparaison matlab/code')




