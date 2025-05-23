package exercicioViagem;

public class Pacote {
    private String nome;
    private Evento eventos[];
    private int tamanho = 0;

    public Pacote(String nome, int quantEventos){
        this.nome = nome;
        this.eventos = new Evento[quantEventos];
    }

    public Pacote(String nome){
        this(nome, 30);
    }

    public Pacote(){
        this("pacote", 30);
    }

    public void adicionaEvento(String nome){
        if(this.tamanho < this.eventos.length) eventos[this.tamanho++] = new Evento(nome);
    }

    public String getNomePacote(){
        return this.nome;
    }

    public void setNomePacote(String nome){
        this.nome = nome;
    }

    public String getNomeEventoX(int i){
        if(i < tamanho) return eventos[i].getNome();
        else return "Esse evento nao existe";
    }

    public void setNomeEventoX(String nome, int i){
        if(i < tamanho) eventos[i].setNome(nome);
    }
}
