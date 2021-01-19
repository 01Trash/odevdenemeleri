clear; close all; clc;

NN=readcell('abc.xlsx','Range','BL8:BL32');

X=xlsread('abc.xlsx','BI8:BI32');
Y=xlsread('abc.xlsx','BJ8:BJ32');
Z=xlsread('abc.xlsx','BK8:BK32');
Z1=xlsread('abc.xlsx','BO8:BO32');
Z2=xlsread('abc.xlsx','BP8:BP32');
Z3=xlsread('abc.xlsx','BP8:BP32');

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



