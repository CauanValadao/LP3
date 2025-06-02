package listaExercicio1Java;

public class Circulo extends Forma {
    private double raio;

    public Circulo(double raio) {
        if(raio > 0) this.raio = raio;
        else this.raio = 1; 
    }

    public double diametro(){
        return raio / 2;
    }

    @Override
    public double area(){
        return Math.PI * raio * raio;
    }

    public double circunferencia(){
        return Math.PI * 2 * raio;
    }
}
