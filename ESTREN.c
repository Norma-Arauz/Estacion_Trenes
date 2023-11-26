/* programa que simule el funcionamiento de asignar pasajeros para que puedan realizar un viaje a la
   ciudad del Fin del Mundo en tren.
   -> Crear formaciones con M vagones
   -> dar  de baja a un vagon si este tiene menos del 50 %
   -> En caso que no haya vagones suficientes colocarlos en una lista de espera
   -> Dar de baja y subir uuna reserva en la lista de espera
   -> Informar de la cantidad de vagones  */
   
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #define  MAXT 4
   #define  MAXV 4
   #define MAXA 5
   
   //Estructura de la reserva 
   typedef struct 
   {
   	 char name[25]; 
   	 int cantAs;  //Cantidad de asientos
   	 int numVagon;
   	 float cost;
   }RESERVA;
   
   //Estrutura de la cola de espera
   typedef struct NODE
   {
   	 RESERVA reser;
   	 struct NODE *next;
   }TIPNODE;
   
   typedef TIPNODE *cola;
   typedef TIPNODE *Nnode;
   
   //Estructura del vagon 
   typedef struct vagon
   {
   	 int IDVa; //identificador de cada vagon 
   	 int asienD; //asientos disponibles
   	 int asienOC; //asientos ocupados
   	 int vag;
   	 struct vagon *next,*last;
   }LOCOMO;
   
   typedef LOCOMO *Nvagon;
   typedef LOCOMO *TREN;
   
   //Prototipos de funciones 
   //Generales
   int numAl(int);
   int menuP();
   int menuR();
   int menuE();
   int menuT(int);
   void reiniciar();
   //Funciones del vagon
   void nuevoVa(TREN *,int);  
   void bajaVa(TREN *);
   void mostrarVa(TREN *);
   void update(TREN *);
   void buscar(TREN *);
   //Funciones de la cola de espera
   void insert(int);
   void remover(int);
   void mostrar(int);
   
   //Variables Globales
   int cont[4],i,j;
   int contC[2],contV,col;
   int elec,m;
   TREN trenes[MAXT];
   cola front[2],end[2];
   
   main()
   {
      int opc,prob,var;
      int t;
      contV=0;
      
      for(j=0;j<2;j++)
      {
      	front[j]=end[j]=NULL;
        contC[j]=0;
	  }
            
	  for(i=0;i<MAXT;i++)
	  {
	  	cont[i]=0;
	  	trenes[i]=NULL;
	  }	
	  t=col=0;
	  
	  while(opc!=5)
	  {
	  	BEGIN:
	  	 system("cls");
	  	 opc=menuP();
	  	 system("cls");
	  	
	  	switch(opc)
	  	{
	  		case 1: printf("\n");
	  		        prob=0;
	  		        while(prob!=4)
	  		        {
	  		      	  system("cls");
	  		          prob=menuR();
	  		          
	  		          system("cls");
	  		          switch(prob)
	  		          {
	  		        	 case 1: printf("\n");
	  		        	         insert(0);
	  		        	         system("pause");
	  		        	         break;
	  		        	        
	  		        	 case 2: printf("\n");
	  		        	         remover(0);
	  		        	         system("pause");
	  		        	         break;
	  		        	        
	  		        	 case 3: printf("\n");
	  		        	         mostrar(0);
	  		        	         system("pause");
	  		        	         break;
	  		        	        
	  		        	 case 4 :printf("\n\t\t -> Regresando al menu <- \n\n");
	  		        	         system("pause");
	  		        	         goto BEGIN;
	  		        	         break;
	  		        	         
	  		        	default: printf("\n\t\t ERROR: Opcion no valida \n\n");
			                     system("pause");
			                     break;
					   }
			        }
					system("pause");
					break;
			case 2: printf("\n");
	  		        var=0;

	  		        while(var!=5)
	  		        {
	  		      	  system("cls");
	  		          var=menuT(t);
	  		          system("cls");
	  		          switch(var)
	  		          {
	  		        	 case 1: printf("\n");
	  		        	         nuevoVa(&trenes[t],m);
	  		        	         m++;
	  		        	         system("pause");
	  		        	         break;
	  		        	        
	  		        	 case 2: printf("\n");
	  		        	         bajaVa(&trenes[t]);
	  		        	         system("pause");
	  		        	         break;
	  		        	        
	  		        	 case 3: printf("\n");
	  		        	         update(&trenes[t]);
	  		        	         buscar(&trenes[t]);
	  		        	         system("pause");
	  		        	         break;
	  		        	   
						 case 4: printf("\n");
						         update(&trenes[t]);
						         mostrarVa(&trenes[t]);
								 system("pause");
								 break;
								      
	  		        	 case 5 :printf("\n \t\t -> Regresando al menu  <- \n\n");
	  		        	         system("pause");
	  		        	         goto BEGIN;
	  		        	         break;
	  		        	         
	  		        	default: printf("\n\t\t ERROR: Opcion no valida \n\n");
			                     system("pause");
			                     break;
					   }
			        }
					system("pause");
					break;
			case 3: printf("\n");
	  		        elec=0;
	  		        while(elec!=3)
	  		        {
	  		      	  system("cls");
	  		          elec=menuE();
	  		          
	  		          system("cls");
	  		          switch(elec)
	  		          {
	  		        	 case 1: printf("\n");
	  		        	         remover(1);
	  		        	         system("pause");
	  		        	         break;
	  		        	        
	  		        	 case 2: printf("\n");
	  		        	         mostrar(1);
	  		        	         system("pause");
	  		        	         break;
	  		        	        
	  		        	 case 3 :printf("\n\t\t -> Regresando al menu <- \n\n");
	  		        	         system("pause");
	  		        	         goto BEGIN;
	  		        	         break;
	  		        	         
	  		        	default: printf("\n\t\t ERROR: Opcion no valida \n\n");
			                     system("pause");
			                     break;
					   }
			        }
					system("pause");
					break;
			
			case 4: printf("\n\t\t %c El siguiente tren esta llegando %c \n\n",254,254);
			        reiniciar();
			        t++;
			        system("pause");
			        goto BEGIN;
			        break;
			        
			case 5: printf("\n\t\t Saliendo del programa \n");
			        system("pause");
			        break;
			        
			default: printf("\n\t\t ERROR: Opcion no valida \n\n");
			         system("pause");
			         break;
		}
	  }
   }
   //reinicia los vagones y las colas --------------------------------------------------------------------------------------------------------------------
   void reiniciar()
   {
   	  int k;
   	
	 for(k=0;k<MAXT;k++)
	   cont[k]=0;
	   
	 front[0]=front[1];
	 end[0]=end[1];
	 contC[0]=contC[1];
	 
	 front[1]=end[1]=NULL;
	 contC[1]=contV=0;
	 m=0;
	 
	 return;
   }
   
   //Funcion que genera numeros de forma aleatoria -------------------------------------------------------------------------------------------------------
   int numAl(int max)
   {
   	 srand(time(0));
   	 
   	 return rand()%max+1;
   }
   
   //Menu principal --------------------------------------------------------------------------------------------------------------------------------------
   int menuP()
   {
   	 int op;
   	 
   	 printf("\t\t-------------------------------------------------- \n");
   	 printf("\t\t| %c Bienvenido a la Estacion de trenes %c          |\n\n",254,254);
   	 printf("\t\t| 1.Reservas \t\t \t\t          | \n");
   	 printf("\t\t| 2.Trenes \t\t \t\t          |\n");
   	 printf("\t\t| 3.Lista de Espera  \t\t \t\t  | \n");
   	 printf("\t\t| 4.Crear otro tren \t\t \t\t  |\n");
   	 printf("\t\t| 5.Salir   \t\t \t\t          |\n");
   	 printf("\t\t --------------------------------------------------- \n\n");
   	 printf("\t\t  Opcion: ");
   	 scanf("%d",&op);
   	
   	 
   	 return op;
   }
   
   //Menu de la lista de espera --------------------------------------------------------------------------------------------------------------------------
   int menuE()
   {
   	  int opr;
   	  
   	 printf("\n \t\t %c Lista de Espera %c \n\n",254,254);
   	 printf("\t\t 1.Dar de baja \n");
   	 printf("\t\t 2.Mostrar las reservas \n");
   	 printf("\t\t 3.Regresar \n");
   	 printf("\t\t Opcion:");
   	 scanf("%d",&opr);
   	 
   	 return opr;
   }
   
   //Menu de reservas  -----------------------------------------------------------------------------------------------------------------------------------
   int menuR()
   {
   	 int alter; //de alternativa
   	 
   	 printf("\n \t\t %c Menu De reservas %c \n\n",254,254);
   	 printf("\t\t 1.Crear una nueva\n");
   	 printf("\t\t 2.Dar de baja \n");
   	 printf("\t\t 3.Mostrar las reservas \n");
   	 printf("\t\t 4.Regresar \n");
   	 printf("\t\t Opcion:");
   	 scanf("%d",&alter);
   	 
   	 return alter;
   }
   
   //Menu de operaciones del tren ------------------------------------------------------------------------------------------------------------------------
   int menuT(int tre)
   {
   	 int dec; //de decision
   	  
   	 printf("\n\t\t %c Tren %d %c \n\n",254,tre+1,254);
   	 printf("\t\t 1.Nuevo vagon \n");
   	 printf("\t\t 2.Dar de baja un Vagon \n");
   	 printf("\t\t 3.Buscar un vagon \n");
   	 printf("\t\t 4.Estado del tren \n");
   	 printf("\t\t 5.Regresar \n");
   	 printf("\t\t Opcion:");
   	 scanf("%d",&dec);
   	 
   	 return dec;
   }
   
   //Operaciones de la cola ------------------------------------------------------------------------------------------------------------------------------
   
   //Se ingresan los elementos en la Cola ----------------------------------------------------------------------------------------------------------------
  void insert(int a)
  {
  	Nnode nuevo;
  	
  	nuevo=(Nnode)malloc(sizeof(TIPNODE));
  	
  	//Llenado de datos
  	nuevo->reser.numVagon=numAl(MAXV);
  	nuevo->reser.cantAs=numAl(5);
  	nuevo->reser.cost=20*nuevo->reser.cantAs;
  	
  	if(cont[nuevo->reser.numVagon-1]>MAXA || (cont[nuevo->reser.numVagon-1]+nuevo->reser.cantAs)>MAXA)
  	{
  	  a=1;
  	  printf("\t\t su Reserva sera transferida a la lista de espera \n\n");
    }
  	else
  	  cont[nuevo->reser.numVagon-1]+=nuevo->reser.cantAs;
  	  
  	printf("\t\t %c Ingrese un nombre: ",254);
  	fflush(stdin);
  	gets(nuevo->reser.name);
  	
  	
  	printf("\n");
  	printf("\t\t -> Datos de la reserva <- \n\n");
  	printf("\t\t -> Nombre:  %s \n",nuevo->reser.name);
  	printf("\t\t -> Cantidad de asientos: %d \n",nuevo->reser.cantAs);
  	printf("\t\t -> Vagon asignado: %d \n",nuevo->reser.numVagon);
  	printf("\t\t -> Total a pagar: %.2f \n\n",nuevo->reser.cost);
  	nuevo->next=NULL;
  	    
  	if(front[a]==NULL)
  	{
  	  front[a]=nuevo;
  	  end[a]=nuevo;
	}
    else
    {
      end[a]->next=nuevo;
      end[a]=nuevo;
	}	
  	contC[a]++;
  	
  	return ;
  }
  
  //Se retiran elementos de la cola ---------------------------------------------------------------------------------------------------------------------
  void remover(int b)
  {
  	Nnode temp;
  	
  	if(front[b]==NULL )
  	  printf("\t\t %c No hay nadie esperando %c \n\n",254,254);
  	else
  	 {
  	      
  	 	temp=front[b];
  	 	front[b]=temp->next;
  	 	printf("\t\t Datos de la Reserva dada de baja \n\n");
  	 	printf("\t\t -> Nombre:  %s \n",temp->reser.name);
  	    printf("\t\t -> Cantidad de asientos: %d \n",temp->reser.cantAs);
  	    printf("\t\t -> Vagon asignado: %d \n",temp->reser.numVagon);
  	    printf("\t\t -> Total a pagar: %.2f \n\n",temp->reser.cost);
  	 	temp->next=NULL;
  	 	free(temp);
  	 	contC[b]--;
  	 	cont[temp->reser.numVagon-1]-=temp->reser.cantAs;
	 }
	 
	 return;
  }
   
  //Muestra los elementos de la cola ---------------------------------------------------------------------------------------------------------------------
  void mostrar(int c)
  {
  	 if(front[c]==NULL)
  	  printf("\t\t %c No hay nadie esperando %c \n\n",254,254);
  	 else
  	   { 
  	      Nnode temp;
  	      temp=front[c];
  	      
  	      printf("\n\t\t No.Vagon ->  Asientos ->    Nombre \n\n");
  	      while(temp!=NULL)
  	      {
  	      	 printf("\t\t | %d | \t ->    | %d | \t -> | %s | \n",temp->reser.numVagon,temp->reser.cantAs,temp->reser.name);
  	      	 fflush(stdin);
  	      	 printf("\t\t -----  \t-----  \t    ------------\n");
  	      	 temp=temp->next;
		  }
		  printf("\t\t ->  NULL <- \n\n");
		  printf("\t\t -> Cantidad de personas en la cola %d \n\n",contC[c]);
	   }
	   return;
  }
  
  //Operaciones de los trenes ----------------------------------------------------------------------------------------------------------------------------
  
   //Insercion de elementos en la lista
   void nuevoVa(TREN *vagon,int n)
   {
   	  Nvagon nuevo,act; //ACT representa a Actual
   	  int val;
   	  
   	  if(contV<MAXV)
   	  {
   	    nuevo=(Nvagon)malloc(sizeof(LOCOMO));
   	  
   	    val=numAl(100);
   	  
   	    //Ingreso la informacion
   	    nuevo->IDVa=val;
   	    nuevo->last=NULL;
   	    nuevo->asienD=MAXA;
   	    nuevo->asienOC=0;
   	    nuevo->vag=n;
   	    
   	    //se coloca act en la primera posicion del tren
   	    act=*vagon;
   	  
   	    if(act)
   	    {
   	      while(act->last)
   	       act=act->last;
        }
        
        //En caso de que el tren este vacio o el ID del vagon sea mayor al actual
        if(!act || act->IDVa>val)
        {
      	   //se a�ade el nuevo vagon
      	   nuevo->next=act;
      	   nuevo->last=NULL;
      	   if(act)
      	     act->last=nuevo;
      	   *vagon=nuevo;
	     }
	     else
	     {
	       //Localizamos el ultimo vagon o hasta encontrar un vagon con id mayor a el que tenemos 
	       while(act->next && act->next->IDVa <= val)
	         act=act->next;
	       //anclamos el vagon
	       nuevo->next=act->next;
	       act->next=nuevo;
	       nuevo->last=act;
	       if(nuevo->next)
	        nuevo->next->last=nuevo;
        }
        printf("\n \t\t El vagon ha sido anclado con exito \n\n");
  
       contV++;
      }
      else
        printf("\t\t No hay vagones disponibles debera esperar el siguiente tren \n\n");
      
      return;
   }
   
   //Se retiran o dan de Baja los vagones ----------------------------------------------------------------------------------------------------------------
   void bajaVa(TREN *vagon)
   {
   	  Nvagon temp;
   	  int elim,aux;
   	  
   	  if(*vagon==NULL)
   	   printf("\t\t -> El tren ya partio \n\n");
   	  else
   	  {
   	    printf("\t\t %c ingrese el ID del vagon:",254);
   	     scanf("%d",&elim);
   	    
   	     temp=*vagon;
   	     aux=MAXA*0.50;
   	     
   	        //Se busca el vagon con el id 
		 while(temp && temp->IDVa <elim)
   	       temp=temp->next;
   	     while(temp && temp->IDVa > elim)
   	       temp=temp->last;
   	       
   	     if(!temp || temp->IDVa != elim)
   	     {
   	  	    printf("\t\t -> El vagon %d no se encuentra disponible \n\n",elim);
   	  	    goto FIN;
         }
         
        if(temp->asienD>aux)
   	     {
           if(temp==*vagon)
           {
       	     if(temp->last)
       	       *vagon=temp->last;
       	     else
       	      *vagon=temp->next;
	       }
	   
	       if(temp->last) //Un vagon que no sea es el primero
	         temp->last->next=temp->next;
	       if(temp->next)  //Un vagon cuyo id no es el ultimo 
	        temp->next->last=temp->last;
	      
	       printf("\n\t\t El vagon se ha dado de baja \n\n");

           contV--;
           FIN:
            free(temp);
         }
         else
           printf("\n \t\t El vagon no se puede dar de baja \n \t\t ya que cumple con el minimo de pasajeros \n\n");

     }
      return;
   }
   
   //Busca la informacion de Vagones especificos
  void buscar(TREN *vagon)
   {
   	 Nvagon aux;
   	 int val;
   	 
   	 aux=*vagon;
   	 
   	 if(aux==NULL)
   	   printf("\t\t -> El tren ya partio \n\n");
   	 else
   	 {
   	  printf("\t\t ->Ingrese el ID del vagon que busca: ");
   	  scanf("%d",&val);
   	 
   	  while(aux && aux->IDVa < val)
   	    aux=aux->next;

   	  while(aux && aux->IDVa > val)
   	   aux=aux->last;
   	
     printf("\n\n");
   	
   	  if(!aux || aux->IDVa != val)
   	   printf("\t\t El vagon con ID %d no se encuentra en el tren \n\n",val);
   	  else
   	   {
   	   	printf("\t\t ----------------------------------------- ");
   	   	printf("\n \t\t| ID: %d                                 |\n",aux->IDVa);
   	   	printf("\t\t| Aientos Ocupados: %d         \t\t |\n",aux->asienOC);
   	   	printf("\t\t| Asientos Disponibles: %d      \t\t |\n",aux->asienD);
   	   	printf("\t\t ----------------------------------------- \n");
   	   	printf("\n");
	   }
    }
    return;
   }
   
   //Actualiza los datos de los asientos de los vagones
   void update (TREN *vagon)
   {
   	 Nvagon upd;
   	 
   	 upd=*vagon;
   	 
   	 if(upd==NULL)
   	  goto RET;
   	 else
   	 {
	   while(upd->next !=NULL)
	    {
   	      upd->asienD=MAXA-cont[upd->vag];
	      upd->asienOC=cont[upd->vag];
	      upd=upd->next;
	    }
	 
	   while(upd->last)
	    upd=upd->last;
	
	  *vagon=upd;
     }
	 
	 RET:
	   return; 
   }
   //Muestra los datos del vagon ------------------------------------------------------------------------------------------------------------------------- 
   void mostrarVa(TREN *vagon)
    {
 	  Nvagon momen;
 	  
      if(*vagon==NULL)
 	    printf("\t\t El tren ya partio \n\n");
 	  else
 	   {
  	     momen=*vagon;
		 
		 printf("\n\t\t  Id  ->  Asientos disponibles \n\n");
 		 while(momen!=NULL)
 		 {
 			printf("\t\t | %d |  ->   | %d | \n",momen->IDVa,momen->asienD);
 			fflush(stdin);
 			printf("\t\t ------     --------- \n");
 			momen=momen->next;
		  }
		  
		 printf("\t\t ->  NULL  <- \n\n");
		 printf("\t\t Cantidad de elementos: %d \n\n",contV);
	   }
	 return;
   }
