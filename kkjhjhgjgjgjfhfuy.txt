clear var
clc


image1=imread('1.jpg');
image2=imread('2.jpg');
image3=imread('3.jpg');
image4=imread('4.jpg');
image5=imread('5.jpg');

im1 = rgb2gray(image1);
im2 = rgb2gray(image2);
im3 = rgb2gray(image3);
im4 = rgb2gray(image4);
im5 = rgb2gray(image5);

im1=imresize(im1,0.1);
im2=imresize(im2,0.1);
im3=imresize(im3,0.1);
im4=imresize(im4,0.1);
im5=imresize(im5,0.1);

