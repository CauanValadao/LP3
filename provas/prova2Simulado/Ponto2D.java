package prova2Simulado;

public class Ponto2D{
    private double x;
    private double y;

    public Ponto2D(double x, double y) {
        this.x = x;
        this.y = y;
    }
    public Ponto2D() {
        this.x = 0;
        this.y = 0;
    }

    public double getX() {
        return x;
    }
    public double getY(){
        return y;
    }

    public void moveXPara(double x){
        this.x = x;
    }
    public void moveYPara(double y){
        this.y = y;
    }

    public void movePara(double x, double y){
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "Ponto2D{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}