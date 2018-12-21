clear all %#ok<CLALL>
clc


x=[1,2,3,4,5];
y=[0,0,0,0,0];
mdata=zeros(1,5);
bdata=zeros(1,5);
error=zeros(1,5);
yf=[0,0,0,0,0];


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

im1=imresize(im1,0.05);
im2=imresize(im2,0.05);
im3=imresize(im3,0.05);
im4=imresize(im4,0.05);
im5=imresize(im5,0.05);



imf=cat(3,im1,im2,im3,im4,im5);

[roww,coll,deapthh]=size(imf);

gfinal=zeros(roww,coll);


for row=1:roww
    for col=1:coll
        for deapth=1:deapthh
            y(deapth)=imf(row,col,deapth);
        end
        yf=y;
        [r,m,b]=regression(x,y);
        
        for i=1:deapthh
            ym=m*i+b;
            y(i)=ym;
            [r,mdata(i),bdata(i)]=regression(x,y);
            y=yf;
            error(i)=abs(m-mdata(i))+abs(b-bdata(i));
        end
        [val,ind]=max(error);
        gfinal(row,col)=yf(ind);
    end
end

subplot(2,3,1),imshow(im1);
subplot(2,3,2),imshow(im2);
subplot(2,3,3),imshow(im3);
subplot(2,3,4),imshow(im4);
subplot(2,3,5),imshow(im5);
subplot(2,3,6),imshow(gfinal,[0,255]);


