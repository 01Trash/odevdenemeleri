clear; close all; clc;

NN=readcell('abc.xlsx','Range','AK15:AK39');

X=xlsread('abc.xlsx','AA15:AA39');
Y=xlsread('abc.xlsx','AB15:AB39');
Z=xlsread('abc.xlsx','AC15:AC39');
Z1=xlsread('abc.xlsx','AH15:AH39');
Z2=xlsread('abc.xlsx','AI15:AI39');
Z3=xlsread('abc.xlsx','AJ15:AJ39');

[s,n]=meshgrid(min(X):500:max(X), min(Y):500:max(Y));

a=griddata(X,Y,Z1,s,n);
b=griddata(X,Y,Z2,s,n);
c=griddata(X,Y,Z3,s,n);

surf(s,n,a,'FaceColor','g')
hold on
surf(s,n,b,'FaceColor','m')
surf(s,n,c,'FaceColor','b')

xlabel('x(m)');
ylabel('y(m)'); 
zlabel('z(m)');
title('abc')

yazlegand=sprintf('Lagrange Trans.');
yazlegand2=sprintf('Direct Solution');
yazlegand3=sprintf('Gauss Trans.');
legend(yazlegand,yazlegand2,yazlegand3);


plot3(X,Y,Z,'or','MarkerFaceColor','y')
text(X,Y,Z+0.2,NN)



