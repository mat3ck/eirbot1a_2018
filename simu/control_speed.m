clear all ; close all ;
more off;

%% Synthèse du système : Moteur DC
s = tf ('s');
z = tf ('z');

K=19.9*10^-3;  %Nm/A
J=35.9*10^-3;  %kgm�
L=0.07;  %H
R=0.358; %ohms
a=0; %coeff de frottement visqueux


A=K/(K^2+a*R)
te=L/R;
to=(R*J)/(K^2+R*a);
G=A/((1+to*s))
% On oublie pas le 1/p pour le gain et la phase de G
w0=1/to;
wu=10*w0
fu=2*pi*wu;

fech=100*fu;
Tech=1/fech

[Module,Arg,wout]=bode(G,wu);
Module=20*log10(Module);
[num,den] = tfdata(G);
Coeff_Gn= cell2mat(num)
Coeff_Gd= cell2mat(den)


%% Coefficient PID

ti=10/wu;
tf=1/(10*wu);

Phi=-90-(Arg-6-6);     %Marge de phase de 60°
a=(1+sind(Phi))/(1-sind(Phi));
ta=sqrt(a)/wu;
tb=1/(wu*sqrt(a));

C0=10^((-10*log10(a)-Module)/20);
C1=(1+ti*s)/(ti*s);
C2=(1+ta*s)/(1+tb*s);
C3=1/(1+tf*s);


C = C0*C1*C2*C3
[num,den] = tfdata(C);
Coeffn=cell2mat(num)
Coeffd=cell2mat(den)


%% Discrétisation
%Tech=(A*sqrt(2)-1)/(to*2*pi);
u = sym('u');
s = sym('s');

Cd = c2d(C,Tech,'zoh')

[num,den] = tfdata(Cd);
Coeffnd=cell2mat(num)
Coeffdd=cell2mat(den)


bode(Cd*G,Cd, G)


%% Odométrie
res_encod=4096/360;
coeff_distance=res_encod*0.003;  % distances en mm
espacement_roue=0.24; % en mm