clear all
close all
clc

K=1;
xi_s=1;
wn_s=3e3;
T1=1/wn_s;
Te=1e-4;

H=tf(K,[T1^2 2*T1 1]);
H_z=c2d(H,Te);

[num_z,den_z]=tfdata(H_z);

xi_bf=1;
wn_bf=1/(2*xi_bf*T1);
Ki=T1*wn_bf/(K*2*xi_bf);
Ti=T1;

P_I=tf([Ki*Ti Ki],[Ti 0]);
P_I_z=c2d(P_I,Te);

[num_pi,den_pi]=tfdata(P_I_z);

sim('schema');

figure;
plot(t,y_ref,'r');
hold on;
plot(t,y_simu,'b');
hold off;
grid on;
legend('y_r_e_f','y');
title('Correction 2e ordre par PI');

b1_pi=0.25;
b0_pi=-0.1750;

a1_pi=1;
a0_pi=-1;

b1_s=0.0369;
b0_s=0.0302;

a2_s=1;
a1_s=-1.4816;
a0_s=0.5488;

load('y.txt')

tech=[0:Te:0.0149];

figure;
plot(tech,y_ref,'r');
hold on;
plot(tech,y,'bo');
hold on;
plot(tech,y_simu,'r+');
hold off;
grid on;
legend('y_r_e_f','y','y_s_i_m_u');
title('Correction 2e ordre par PI');


