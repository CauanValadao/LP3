package Prova1;

public class Lampada {
    private float estado;
    private int id;
    private static int serial = 0;

    public Lampada(){
        this.estado = 0.0f;
        this.id = ++serial;
    }
    public Lampada(float estado){
        if(estado < 0.0f || estado > 1.0f)
            this.estado = 0.0f;
        else
            this.estado = estado;
        this.id = ++serial;
    }
    
    public float getIntensidade(){
        return this.estado;
    }
    public int getId(){
        return this.id;
    }
    public void setIntensidade(float estado){
        if(estado < 0.0f)
            this.estado = 0.0f;
        else if(estado > 1.0f)
            this.estado = 1.0f;
        else
            this.estado = estado;
    }
    public void ligar(){
        this.estado = 1.0f;
    }
    public void ligar(float estado){
        if(estado < 0.0f)
            this.estado = 0.0f;
        else if(estado > 1.0f)
            this.estado = 1.0f;
        else
            this.estado = estado;
    }
    public void desligar(){
        this.estado = 0.0f;
    }
    public void aumentar(){
        if(this.estado < 1.0f)
            this.estado += 0.1f;
    }
    public void diminuir(){
        if(this.estado > 0.0f)
            this.estado -= 0.1f;
    }
    public boolean estaLigado(){
        return this.estado > 0.0f;
    }
    public static int quantosIds(){
        return serial;
    }
}
