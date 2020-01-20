function val=mafonctiona(x,y)
    //unecloche
    val=16*x*(x-1)*y*(y-1)
endfunction
function val=mafonctionb(x,y)
    //oscillation
    val=sin(2*%pi*x)*sin(3*%pi*y)
endfunction
a=0;
b=1;
N=40;
x=linspace(a,b,N);
y=linspace(a,b,N);
za=feval(x,y,mafonctiona);
zb=feval(x,y,mafonctionb);
//z_ij=mafonction(xi,yj) pour tous les couples x_i,y_j)voir help feval
//za ou zb sera donc ici un tableau N*N
mb=min(zb);
Mb=max(zb);
ma=min(za);
Ma=max(za);
ma_boite_a_couleur=jetcolormap(256);

clf(1);
g=scf(1);//f1
g.color_map=ma_boite_a_couleur; // def d'une carte de couleur
colorbar(ma,Ma);
plot3d1(x,y,za);
h=get("hdl");
h.color_mode=-2;


clf(2);
g=scf(2);//f2
g.color_map=ma_boite_a_couleur; // def d'une carte de couleur
colorbar(mb,Mb);
plot3d1(x,y,zb);
h=get("hd1");
h.color_mode=-2;

