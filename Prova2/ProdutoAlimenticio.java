public class ProdutoAlimenticio extends Produto {
    private String dataValidade;
    private double pesoKg;

    public ProdutoAlimenticio(String nome, double preco, int estoque, String dataValidade, double pesoKg) {
        super(nome, preco, estoque);
        if (pesoKg >= 0) this.pesoKg = pesoKg;
        else this.pesoKg = 10.0;
        this.dataValidade = dataValidade;
    }

    public String getDataValidade() {
        return this.dataValidade;
    }
    public double getPesoKg() {
        return this.pesoKg;
    }
    public void setDataValidade(String dataValidade) {
        this.dataValidade = dataValidade;
    }
    public void setPesoKg(double pesoKg) {
        if (pesoKg >= 0) this.pesoKg = pesoKg;
    }
    public String toString() {
        return super.toString() + ", Data de Validade: " + this.dataValidade + ", Peso: " + this.pesoKg + " kg";
    }
}
