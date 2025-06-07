public class Produto {
    private String nome;
    private double preco;
    private int estoque;

    public Produto(String nome, double preco, int estoque){
        this.nome = nome;
        if(preco >= 0) this.preco = preco;
        else this.preco = 10;
        if(estoque >= 0) this.estoque = estoque;
        else this.estoque = 10;
    }

    public String getNome(){
        return this.nome;
    }
    public double getPreco(){
        return this.preco;
    }
    public int getEstoque(){
        return this.estoque;
    }
    public void adEstoque(int quant){
        if(quant >= 0) this.estoque += quant;
    }
    public boolean remEstoque(int quant){
        if(quant < 0 || quant > this.estoque) return false;
        this.estoque -= quant;
        return true;
    } 

    public String toString(){
        return "nome: " + this.nome + ", Preco: " + this.preco + ", Estoque: " + this.estoque;
    }
}
