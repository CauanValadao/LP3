public class CarrinhoDeCompras {
    private Produto[] carrinho;
    private int quantCarrinho = 0;

    public CarrinhoDeCompras(int quantMax){
        if(quantMax > 0) 
            this.carrinho = new Produto[quantMax];
        else 
            this.carrinho = new Produto[10];
    }

    public boolean adicionarItem(Produto produto, int quantidade){
        if(quantidade <= 0 || this.quantCarrinho >= this.carrinho.length || quantidade > produto.getEstoque()) return false;
        carrinho[quantCarrinho++] = new Produto(produto.getNome(), produto.getPreco(), quantidade);
        produto.remEstoque(quantidade);
        return true;
    }

    public boolean removerItem(Produto produto, int quantidade){
        if(quantidade <= 0) return false;

        for(int i = 0; i < quantCarrinho; i++){
            if(podeRemover(carrinho[i], produto, quantidade)){
                carrinho[i].remEstoque(quantidade);
                if(carrinho[i].getEstoque() == 0){
                    for(int j = i; j < quantCarrinho - 1; j++){
                        carrinho[j] = carrinho[j + 1];
                    }
                    quantCarrinho--;
                    carrinho[quantCarrinho] = null;
                }
                return true;
            }
        }
        return false;
    }

    public static boolean podeRemover(Produto produto1, Produto produto2, int quantidade) {
        if(produto1.getNome() != produto2.getNome() || produto1.getPreco() != produto2.getPreco() || produto1.getEstoque() < quantidade) {
            return false;
        }
        return true;
    }

    public double calcularTotal() {
        double soma = 0;
        for(int i = 0; i < quantCarrinho; i++){
            soma += carrinho[i].getPreco() * carrinho[i].getEstoque();
        }
        return soma;
    }

    public void exibirItens(){
        for(int i = 0; i < quantCarrinho; i++){
            System.out.println("item "+ i + ": " + carrinho[i].toString());
        }
    }
}
