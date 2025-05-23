package exercicioViagem;

public class Evento {
    private String nome;
    
    public Evento(String nome){
        this.nome = nome;
    }
    public Evento(){
        this("evento");
    }

    public String getNome(){
        return this.nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
    
}
