disp('Hello, world!');
f=fopen('imagenes/salida.raw','r');
M=fread(f,'float');
M=reshape(M, 2001, 2001);
imagesc(M);
colormap([jet(); flipud( jet()); 0 0 0]);
pause ();


