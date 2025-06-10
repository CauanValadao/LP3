package prova2Simulado;

public class Ponto3D extends Ponto2D {
    private double z;

    public Ponto3D(double x, double y, double z){
        super(x, y);
        this.z = z;
    }
    public Ponto3D(){
        super();
        this.z = 0;
    }

    public double getZ(){
        return this.z;
    }

    public void moveZPara(double z){
        this.z = z;
    }

    public void movePara(double x, double y, double z){
        super.movePara(x, y);
        this.z = z;
    }

    public String toString(){
        return "Ponto3D{" +"x=" + getX() +", y=" + getY() +", z=" + z +'}';
    }

}
