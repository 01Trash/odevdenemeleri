clear; close all; clc;

NN=readcell('abc.xlsx','Range','J8:J32');

X=xlsread('abc.xlsx','G8:G32');
Y=xlsread('abc.xlsx','H8:H32');
Z=xlsread('abc.xlsx','I8:I32');
Z1=xlsread('abc.xlsx','L8:L32');
Z2=xlsread('abc.xlsx','M8:M32');
Z3=xlsread('abc.xlsx','N8:N32');

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



