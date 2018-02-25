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
% w0=sqrt((K^2+a*R)/(L*J))
% E=(w0*(R*J+a*L))/((K^2+a*R)*2)
% 
% G=A/(1+(2*E*s)/w0+(s^2)/(w0^2))    
te=L/R;
to=(R*J)/(K^2+R*a);
G=A/((1+to*s))
% On oublie pas le 1/p pour le gain et la phase de G
K=G/s
w0=1/to;
wu=10*w0
fu=2*pi*wu;

fech=100*fu;
Tech=1/fech

[Module,Arg,wout]=bode(K,wu)
Module=20*log10(Module)

%% Coefficient PID

ti=10/wu;
tf=1/(10*wu);

Phi=-110-(Arg-6-6);     %Marge de phase de 60°
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
Kd = c2d(K,Tech,'zoh')

[num,den] = tfdata(Cd);
Coeffnd=cell2mat(num)
Coeffdd=cell2mat(den)

[num,den] = tfdata(Kd);
CoeffKdn=cell2mat(num)
CoeffKdd=cell2mat(den)

%[m,n]=size(Coeff)
s=poly2sym(den,s);
U=poly2sym(num,u);


bode(Cd*Kd,Cd, Kd)
%bode(C*K,C1,C2,C3,K)

%% Odométrie
res_encod=4096/360;
coeff_distance=res_encod*0.003;  % distances en mm
espacement_roue=0.24; % en mm


