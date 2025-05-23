package exercicioViagem;

public class Evento {
    private String nome;
    private int duracao;
    
    public Evento(String nome, int duracao){
        this.nome = nome;
        this.duracao = duracao;
    }
    public Evento(String nome){
        this.nome = nome;
        this.duracao = 10;
    }
    public Evento(){
        this.nome = "fulano";
        this.duracao = 10;
    }

    public String getNome(){
        return this.nome;
    }

    public int getDuracao(){
        return this.duracao;
    }
    
}
