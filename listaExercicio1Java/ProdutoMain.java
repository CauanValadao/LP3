package listaExercicio1Java;

public class ProdutoMain {
    
    public static void main(String[] args){
        Produto produto = new Produto("chaveiro", 20.5);
        System.out.println(produto.getPreco());
        produto.desconto();
        System.out.println(produto.getPreco());
    }
    
}
