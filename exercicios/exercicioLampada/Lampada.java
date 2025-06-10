package exercicioLampada;

public class Lampada {
    boolean estado = false;
    double potencia;
    int qLigar = 0;
    int limite;

    public Lampada(double potencia, int limite){
        this.potencia = potencia;
        this.limite = limite;
    }

    public Lampada(){
        this(100,100);
    }

    public boolean devoTrocar(){
        if(this.qLigar > this.limite) return true;
        return false;
    }
    public static boolean devoTrocar(Lampada lampada){
        if(lampada.qLigar > lampada.limite) return true;
        return false;
    }

    public boolean estaLigado(){
        return this.estado;
    }

    public void ligar(){
        if(!devoTrocar() && !estaLigado()){
            this.estado = true;
            this.qLigar++;
        }
    }

    public void desligar(){
        if(estaLigado()) this.estado = false;
    }

    public double qualPotencia(){
        return potencia;
    }

}
