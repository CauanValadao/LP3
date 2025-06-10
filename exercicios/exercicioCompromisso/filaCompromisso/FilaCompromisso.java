package exercicioCompromisso.filaCompromisso;
import exercicioData.*;

public class FilaCompromisso {
    private Data[] fila;
    private int tam = 0;

    public FilaCompromisso(int capacidade){
        fila = new Data[capacidade];
    }
    public FilaCompromisso(){
        fila = new Data[10];
    }

    private int buscaIndice(Data data){
        for(int i = 0; i < tam; i++)
            if(fila[i].igualA(data)) return i;
        return -1;
    }

    public boolean verificaCompromisso(Data data){
        if(buscaIndice(data) != -1) return true;
        return false; 
    }

    public boolean adicionaCompromisso(Data data){
        if(this.tam >= fila.length || verificaCompromisso(data)) return false;
        for(int i = this.tam; i > 0; i++)
            fila[i] = fila[i-1];
        fila[0] = data;
        return true;
    }

    public boolean desmarcaCompromisso(){
        if(tam < 1) return false;
    //  fila[tam - 1].setData(1,1,1);
        tam--;
        return true;
    }
    public void listaCompromisso(){
        for(int i = 0; i < this.tam; i++){
            System.out.println(fila[i]);
        }
        
    }
}
