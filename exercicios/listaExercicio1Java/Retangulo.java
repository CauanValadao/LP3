package listaExercicio1Java;

public class Retangulo extends Forma {
    private double altura;
    private double largura;

    public Retangulo(double altura, double largura) {
        if(altura > 0) this.altura = altura;
        else this.altura = 1; 
        if(largura > 0) this.largura = largura;
        else this.largura = 1; 
    }
    public Retangulo(double altura) {
        this(altura, 1);
    }
    public Retangulo() {
        this(1, 1);
    }

    public double getAltura(){
        return this.altura;
    }
    public double getLargura(){
        return this.largura;
    }
    public void setAltura(double altura){
        if(altura > 0) this.altura = altura;
    }
    public void setLargura(double largura){
        if(largura > 0) this.largura = largura;
    }

    @Override
    public double area(){
        return largura *altura;
    }
}
