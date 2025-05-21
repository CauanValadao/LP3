package exercicioViagem;

public class Pacote {
    private String nome;
    private Evento eventos[];
    private int tamanho = 0;

    public Pacote(String nome, int quantEventos){
        this.nome = nome;
        this.eventos = new Evento[quantEventos];
    }

    public void adicionaEvento(String nome){
        if(this.tamanho < this.eventos.length) eventos[this.tamanho++] = new Evento(nome);
    }

    public String getNomePacote(){
        return this.nome;
    }
}
