package Prova1;

public class Contador {
    private int contador;

    public Contador(){
        this.contador = 0;
    }

    public Contador(int i){
        this.contador = i;
    }

    int getContador(){
        return this.contador;
    }

    void incrementa(){
        this.contador++;
    }

    void decrementa(){
        this.contador--;
    }

    boolean menorQue(int j){
        return this.contador < j;
    }

    boolean igualA(int j){
        return this.contador == j;
    }

    boolean maiorQue(int j){
        return this.contador > j;
    }

}
