package listaExercicio1Java;

public class Produto {
    private String nome;
    private double preco;

    public Produto(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
    }
    public Produto(String nome) {
        this(nome, 0.0);
    }
    public Produto(double preco) {
        this("Produto", preco);
    }
    public Produto() {
        this("Produto", 0.0);
    }

    public String getNome() {
        return nome;
    }
    public double getPreco() {
        return preco;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void desconto(){
        this.preco *= 0.9;
    }
}
