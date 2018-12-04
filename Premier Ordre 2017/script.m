clear all
close all
clc

%%
ka = 0.1;
Te = 1e-3;
Tf = 0.149;

%%
load('u.txt');
load('y.txt');

t = [0:Te:Tf]';

sim('simulink_testcode.slx')

figure;
hold on
plot(tout, yout,'bo');
plot(t,y,'r+');
hold off
grid on
legend('Simulation','Auto-Codage');
xlabel('t (s)');
ylabel('y');
title('Comparaison Simulation/Auto-Codage');
