package exercicioLampada;

public class SistemaIluminacao {
    Lampada[] sistema;
    int tamanho = 0;

    public SistemaIluminacao(int tamanhoArray){
        if(tamanhoArray >= 30)
            this.sistema = new Lampada[30];
        else
            this.sistema = new Lampada[tamanhoArray]; 
    }
    public SistemaIluminacao(){
        this(30);
    }
    
    public boolean adicionaLampada(double potencia, int limite){
        if(this.tamanho <= this.sistema.length){
            this.sistema[tamanho++] = new Lampada(potencia, limite);
            this.tamanho++;
            return true;
        }
        return false;
    }
    public void adicionaLampada(Lampada lampada){
        adicionaLampada(lampada.potencia, lampada.limite);
    }

    public void ligar(int indice){
        if(indice < this.tamanho)
        this.sistema[indice].ligar();
    }
    public void ligar(){
        for(int i = 0; i < this.tamanho; i++)
            ligar(i);
    }

    public void desligar(int indice){
        if(indice < this.tamanho)
        this.sistema[indice].desligar();
    }
    public void desligar(){
        for(int i = 0; i < this.tamanho; i++)
            desligar(i);
    }

    public boolean verificar(int indice){
        if(indice < this.tamanho){
        return this.sistema[indice].devoTrocar();
        }
        return false;
    }
    public boolean[] verificar(){
        boolean[] quaisTrocar = new boolean[tamanho];
        for(int i = 0; i < tamanho; i++)
            quaisTrocar[i] = verificar(i);
        
        return quaisTrocar;
    }
}
