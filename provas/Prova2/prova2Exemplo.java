public class prova2Exemplo {
    public static void main(String[] args){
        ProdutoEletronico celular = new ProdutoEletronico("s24", 4000.0, 100, 12, "12V");
        ProdutoEletronico notebook = new ProdutoEletronico("notebook", 5000.0, 50, 24, "110V");
        ProdutoAlimenticio arroz = new ProdutoAlimenticio("arroz", 20.0, 200, "2025/12/31", 5.0);
        ProdutoAlimenticio feijao = new ProdutoAlimenticio("feijao", 10.0, 150, "2025/06/30", 2.0);

        CarrinhoDeCompras carrinhoDeCompras = new CarrinhoDeCompras(5);

        carrinhoDeCompras.adicionarItem(celular, 1);
        carrinhoDeCompras.adicionarItem(notebook, 1);
        carrinhoDeCompras.adicionarItem(arroz, 10);
        carrinhoDeCompras.adicionarItem(feijao, 15);

        carrinhoDeCompras.removerItem(feijao, 10);

        System.out.println("preco total: " + carrinhoDeCompras.calcularTotal());
        carrinhoDeCompras.exibirItens();
    }
}