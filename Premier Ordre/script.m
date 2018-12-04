clear all
close all
clc

ka=0.1;
Te=1e-3;


load('Data.txt');
load('u.txt');
load('y.txt');


t=[0:Te:0.149]';

figure;
plot(t,Data,'bo');
hold on
plot(t,y,'r+');
hold off
grid on
legend('Maquette','Auto-Codage');
xlabel('t (s)');
ylabel('y');
title('Comparaison Maquette/Auto-Codage');
