public class ProdutoEletronico extends Produto{
    private int garantiaMeses;
    private String tensaoVoltagem;

    public ProdutoEletronico(String nome, double preco, int estoque, int garantiaMeses, String tensaoVoltagem){
        super(nome, preco, estoque);
        if(garantiaMeses >= 0) this.garantiaMeses = garantiaMeses;
        else this.garantiaMeses = 10;
        this.tensaoVoltagem = tensaoVoltagem; 
    }

    public int getGatantiaMeses(){
        return this.garantiaMeses;
    }
    public String getTensaoVoltagem(){
        return this.tensaoVoltagem;
    }
    public void setGatantiaMeses(int garantiaMeses){
        if(garantiaMeses >= 0) this.garantiaMeses = garantiaMeses;
    }
    public void setTensaoVoltagem(String tensaoVoltagem){
        this.tensaoVoltagem = tensaoVoltagem;
    }
    public String toString(){
        return super.toString() + ", Garantia: " + this.garantiaMeses + " meses, Tensão/Voltagem: " + this.tensaoVoltagem;
    }
}
