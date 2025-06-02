package listaExercicio1Java;

public class Pedido {
    private Produto[] pedido;
    private int quantidade = 0;

    public Pedido(int quantPedido){
        pedido = new Produto[quantPedido];
    }
    public Pedido(){
        this(5);
    }

    public void adicionar_item(Produto produto){
        if(quantidade < pedido.length)
            pedido[quantidade++] = produto;
    }
}
