#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CH_SIZE 16

struct date_time{
	int hours;
	int minutes;
	int days;
	int months;
	int years;
}; 

struct flight{
	int number;
	char *arr_city;
	char *dep_city;
	struct date_time arrival;
	struct date_time departure;
};

struct passenger{
	char *f_name;
	char *l_name;
	char *dep_city;
	char *arr_city;
	struct date_time departure;
	struct flight *reserved;
		
};

int addFlight(struct flight **table, int flight_count);
int printFlight(struct flight *flights, int index);
void reserve(struct flight *table, int flight_count, struct passenger *to_be_reserved);

int main()
{
	struct flight *flights;
	int flight_count = 0;
	struct passenger *passengers;
	int pass_count = 0;
	int i = 0;
	scanf("%d", &flight_count);
	if (!(flights = (struct flight*)malloc(flight_count * sizeof(struct flight)))){
		printf("NO MEMORY\n");
		return 1;
	}
	for (i = 0; i < flight_count; ++i)
	{
		flights[i].arr_city = (char *)malloc(sizeof(char)*CH_SIZE);
		flights[i].dep_city = (char *)malloc(sizeof(char)*CH_SIZE);
		scanf("%d %s %s %d/%d/%d %d:%d %d/%d/%d %d:%d", &flights[i].number, flights[i].dep_city, flights[i].arr_city, &flights[i].departure.days, &flights[i].departure.months, &flights[i].departure.years, &flights[i].departure.hours, &flights[i].departure.minutes, &flights[i].arrival.days, &flights[i].arrival.months, &flights[i].arrival.years, &flights[i].arrival.hours, &flights[i].arrival.minutes);
	}
	scanf("%d", &pass_count);
	if (!(passengers = (struct passenger*)malloc(pass_count * sizeof(struct passenger)))){
		printf("NO MEMORY\n");
		return 1;
	}
	for (i = 0; i < pass_count; ++i)
	{
		passengers[i].f_name = (char *)malloc(sizeof(char)*CH_SIZE);
		passengers[i].l_name = (char *)malloc(sizeof(char)*CH_SIZE);
		passengers[i].dep_city = (char *)malloc(sizeof(char)*CH_SIZE);
		passengers[i].arr_city = (char *)malloc(sizeof(char)*CH_SIZE);
		passengers[i].reserved = NULL;
		scanf("%s %s %s %s %d/%d/%d", passengers[i].f_name, passengers[i].l_name, passengers[i].dep_city, passengers[i].arr_city, &passengers[i].departure.days, &passengers[i].departure.months, &passengers[i].departure.years);
		reserve(flights, flight_count, passengers+i);
		if(passengers[i].reserved == NULL) printf("%s %s %s %s %d/%d/%d No reservation\n", passengers[i].f_name, passengers[i].l_name, passengers[i].dep_city, passengers[i].arr_city, passengers[i].departure.days, passengers[i].departure.months, passengers[i].departure.years);
	}
	char command[CH_SIZE];
	int counter = 0;
	int f_no;
	while(1){
		strcpy(command, "idle");
		counter = 0;
		f_no = 0;
		scanf("%s", command);
		if (!strcmp(command, "search"))
		{
			scanf("%s", command);
			if (!strcmp(command, "flightNumber"))
			{
				scanf("%d", &f_no);
				putchar('\n');
				int i = 0;
				for (i = 0; i < flight_count; ++i)
				{
					if (f_no == flights[i].number)
					{
						counter++;
						printFlight(flights, i);
						putchar('\n');
					}
				}
				if(!counter) printf("No flight with number %d\n", f_no);
				counter = 0;
			} else if (!strcmp(command, "departure"))
			{
				scanf("%s", command);
				putchar('\n');
				int i = 0;
				for (i = 0; i < flight_count; ++i)
				{
					if (!strcmp(command, flights[i].dep_city))
					{
						printFlight(flights, i);
						putchar('\n');
						counter++;
					}
				}
				if(!counter) printf("No departure city %s\n", command);
				counter = 0;
			} else if (!strcmp(command, "arrival"))
			{
				scanf("%s", command);
				putchar('\n');
				int i = 0;
				for (i = 0; i < flight_count; ++i)
				{
					if (!strcmp(command, flights[i].arr_city))
					{
						printFlight(flights, i);
						putchar('\n');
						counter++;
					}
				}
				if(!counter) printf("No arrival city %s\n", command);
				counter = 0;
			}
		} else if(!strcmp(command, "print")){
			int attendants = 0;
			scanf("%d", &f_no);
			putchar('\n');
				int j = 0;
				for (j = 0; j < flight_count; ++j)
				{
					if (f_no == flights[j].number)
					{
						printFlight(flights, j);
						int i = 0;
						for (i = 0; i < pass_count; ++i)
						{
							if(passengers[i].reserved == flights+j){attendants++;}
						}
						printf(" %d\n", attendants);
						break;
					}
				}
		} else if(!strcmp(command, "printwP")){
			int attendants = 0;
			scanf("%d", &f_no);
			putchar('\n');
			int j=0;
			for (j = 0; j < flight_count; ++j)
			{
				if (f_no == flights[j].number)
				{	
					int i = 0;
					printFlight(flights, j);
					for (i = 0; i < pass_count; ++i)
					{
						if(passengers[i].reserved == flights+j){attendants++;}
					}
					printf(" %d\n", attendants);
					for (i = 0; i < pass_count; ++i)
					{
						if(passengers[i].reserved == flights+j){
							printf("%s %s\n", passengers[i].f_name, passengers[i].l_name);
						}
					}
					break;
				}
			}
		} else if(!strcmp(command, "printR")){
			putchar('\n');
			int i = 0;
			char fN[CH_SIZE],lN[CH_SIZE];
			scanf("%s %s", fN,lN);
			for (i = 0; i < pass_count; ++i)
			{
				if(!strcmp(passengers[i].f_name, fN) && !strcmp(passengers[i].l_name, lN)){
					printf("%s %s ", fN, lN);
					printFlight(passengers[i].reserved, 0);
				}
			}

		} else if(!strcmp(command, "END")){
			return 0;
		}
	}
	return 0;
}

int addFlight(struct flight **table, int flight_count){
	struct flight *ptr;
	if (!(ptr = (struct flight*)realloc(*table,(flight_count+1) * sizeof(struct flight)))){
		printf("NO MEMORY\n");
		return 0;
	} else *table = ptr;
	scanf("%d %s %s %d/%d/%d %d:%d %d/%d/%d %d:%d", &(*table)[flight_count].number, &(*table)[flight_count].dep_city, &(*table)[flight_count].arr_city, &(*table)[flight_count].departure.days, &(*table)[flight_count].departure.months, &(*table)[flight_count].departure.years, &(*table)[flight_count].departure.hours, &(*table)[flight_count].departure.minutes, &(*table)[flight_count].arrival.days, &(*table)[flight_count].arrival.months, &(*table)[flight_count].arrival.years, &(*table)[flight_count].arrival.hours, &(*table)[flight_count].arrival.minutes);
	return 1;
}

int printFlight(struct flight *flights, int index){
	printf("%d %s %s %d/%d/%d %02d:%02d %d/%d/%d %02d:%02d", flights[index].number, flights[index].dep_city, flights[index].arr_city, flights[index].departure.days, flights[index].departure.months, flights[index].departure.years, flights[index].departure.hours, flights[index].departure.minutes, flights[index].arrival.days, flights[index].arrival.months, flights[index].arrival.years, flights[index].arrival.hours, flights[index].arrival.minutes);
}

void reserve(struct flight *table, int flight_count, struct passenger *to_be_reserved){
	struct flight *appropiate = NULL;
	int i=0;
	for (i = 0; i < flight_count; ++i)
	{
		if (!strcmp(table[i].dep_city, to_be_reserved->dep_city) && !strcmp(table[i].arr_city, to_be_reserved->arr_city))
		{
			if (table[i].departure.years >= to_be_reserved->departure.years && table[i].departure.months >= to_be_reserved->departure.months && table[i].departure.days >= to_be_reserved->departure.days)
			{
				if(appropiate==NULL) appropiate = table+i;
				else if(appropiate != NULL && (table[i].departure.years <= appropiate->departure.years && table[i].departure.months <= appropiate->departure.months && table[i].departure.days <= appropiate->departure.days && table[i].departure.hours <= appropiate->departure.hours && table[i].departure.minutes <= appropiate->departure.minutes )) appropiate = table+i;
			}
		}
	}
	to_be_reserved->reserved = appropiate;
}