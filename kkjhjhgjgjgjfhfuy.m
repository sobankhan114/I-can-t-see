clear all
clc


x=[1,2,3,4,5];
y=[0,0,0,0,0];
x1=linspace(1,5,100);
num=1;



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

im1=imresize(im1,0.2);
im2=imresize(im2,0.2);
im3=imresize(im3,0.2);
im4=imresize(im4,0.2);
im5=imresize(im5,0.2);




%{

subplot(2,3,1), imshow(im1)
subplot(2,3,2), imshow(im2)
subplot(2,3,3), imshow(im3)
subplot(2,3,4), imshow(im4)
subplot(2,3,5), imshow(im5)

%}




imf=cat(3,im1,im2,im3,im4,im5);




for row=106:116
    for col=405:415
        for deapth=1:5
            y(deapth)=imf(row,col,deapth);
        end
        p=polyfit(x,y,4);
        f1=polyval(p,x1);
        subplot(10,10,num),plot(x1,f1);
        num=num+1;
    end
end


