package exercicioCompromisso.PilhaCompromisso;
import exercicioData.*;

public class PilhaCompromisso{
    private Data[] pilha;
    private int tam = 0;

    public PilhaCompromisso(int capacidade){
        this.pilha = new Data[capacidade];
    }

    public PilhaCompromisso(){
        this.pilha = new Data[10];
    }

    private int buscaIndice(Data data){
        for(int i = 0; i < tam; i++)
            if(pilha[i].igualA(data)) return i;
        return -1;
    }

    public boolean verificaCompromisso(Data data){
        if(buscaIndice(data) != -1) return true;
        return false; 
    }

    public boolean adicionaCompromisso(Data data){
        if(this.tam >= pilha.length || verificaCompromisso(data)) return false;
        pilha[this.tam++] = data;
        return true;
    }

    public boolean desmarcaCompromisso(){
        if(tam < 1) return false;
    //  pilha[tam - 1].setData(1,1,1);
        tam--;
        return true;
    }

    public void listaCompromisso(){
        for(int i = 0; i < this.tam; i++){
            System.out.println(pilha[i]);
        }
        
    }
}