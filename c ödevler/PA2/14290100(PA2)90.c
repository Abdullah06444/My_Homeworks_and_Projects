#include <stdio.h>

int main()
{
	int i=0, j, k, x, y, z, t, nmb[100][4], area, area2;
	char ch;
	while (scanf("%c", &ch))
	{
		
		if (ch== 'r' || ch== 'R' || ch== 's' || ch== 'S')
		{
			
			if (ch== 'r' || ch== 'R')
			{
				
				for (j=0 ; j<4 ; j++)
				{
					
					scanf ("%d", &nmb[i][j]);
				}
				
				i++;
			}
			else if (ch== 's' || ch== 'S')
			{
				
				for (j=0 ; j<3 ; j++)
				{
					
					scanf ("%d", &nmb[i][j]);
					nmb[i][3] = nmb[i][2];
				}
				i++;
			}			
		}
			else if (ch== 'p' || ch== 'P')
			{
				
				scanf ("%c", &ch);
				if (ch== ' ' || ch== '\t' || ch== '\n')
				{
					
					do
					{

					scanf ("%c", &ch);
					}
					while (ch== ' ' || ch== '\t' || ch== '\n');
					if (ch== '-')
					{
						
						scanf ("%c", &ch);
						if (ch== 'd' || ch== 'D')
						{

								printf ("\n__________\n");
								k = 0;
								while (k<i )
								{
								
									printf("[%d] %d %d ", k+1, nmb[k][0], nmb[k][1]);
									printf("%d %d\n", nmb[k][0] + nmb[k][2], nmb[k][1] + nmb[k][3]);
									k++;
								}
								printf ("__________\n");
						}
						else if (ch== 'r' || ch== 'R')
						{
					
								scanf ("%d", &j);
								if (j<=0 );
								else
								{

									if ((j - 1)<i )
									{
								
										area = nmb[j - 1][2]*nmb[j - 1][3];
										printf ("Area of Rectangle [%d] = %d\n", j, area);
									}
								}
						}
						
						else if (ch== 'i' || ch== 'I')
						{

							area2 = 0;
							for (k=0 ;k<i ;k++ )
							{
								
								x = nmb[k][0] + 1;
								for (; x<= (nmb[k][0] + nmb[k][2]); x++)
								{
									
									y = nmb[k][1] + 1;
									for (; y<= (nmb[k][1] + nmb[k][3]); y++)
									{
										
										for (j=(k+1) ;j<i ;j++ )
										{
											
											z = nmb[j][0] + 1;
											for (; z<= (nmb[j][0] + nmb[j][2]); z++)
											{
												
												t = nmb[j][1] + 1;
												for (; t<= (nmb[j][1] + nmb[j][3]); t++)
												{
													
													if (x == z)
													{
														
														if (y == t)
														{
																														
															area2 += 1;
														}
													}
												}
											}
										}
									}
								}
							}							
							printf ("Intersection Area= %d\n", area2);
						}
						else if (ch== 'n' || ch== 'N')
						{

							area=0;
							for (k=0 ;k<i ;k++)
							{
								
								area += (nmb[k][2] * nmb[k][3]);
							}
							area2 = 0;
							for (k=0 ;k<i ;k++ )
							{
								
								x = nmb[k][0] + 1;
								for (; x<= (nmb[k][0] + nmb[k][2]); x++)
								{
									
									y = nmb[k][1] + 1;
									for (; y<= (nmb[k][1] + nmb[k][3]); y++)
									{
										
										for (j=(k+1) ;j<i ;j++ )
										{
											
											z = nmb[j][0] + 1;
											for (; z<= (nmb[j][0] + nmb[j][2]); z++)
											{
												
												t = nmb[j][1] + 1;
												for (; t<= (nmb[j][1] + nmb[j][3]); t++)
												{
													
													if (x == z)
													{
														
														if (y == t)
														{
																														
															area2 += 1;
														}
													}
												}
											}
										}
									}
								}
							}
							
							printf ("Net Rectangle Area= %d\n", (area - area2));
						}
						else if (ch== 'b' || ch== 'B')
						{
					
								if (ch== 'B')
								{
									
									printf ("invalid rectangle index!\n");
								}
								x = nmb[0][0];
								for (k= 0; k< i ; k++)
								{
									
									if (nmb[k][0]<x )
									{
										
										x = nmb[k][0];
									}
								}
								printf ("BBC = [%d ", x);
								x = nmb[0][1];
								for (k= 0; k< i ; k++)
								{
									
									if (nmb[k][1]<x )
									{
										
										x = nmb[k][1];
									}
								}
								printf ("%d ", x);
								x = nmb[0][0] + nmb[0][2];
								for (k= 0; k< i ; k++)
								{
									
									if ((nmb[k][0] + nmb[k][2])>x )
									{
										
										x = nmb[k][0] + nmb[k][2];
									}
								}
								printf ("%d ", x);
								x = nmb[0][1] + nmb[0][3];
								for (k= 0; k< i ; k++)
								{
									
									if ((nmb[k][1] + nmb[k][3])>x )
									{
										
										x = nmb[k][1] + nmb[k][3];
									}
								}
								k=0;
								printf ("%d]\n", x);
						}
						else
						{
							
							printf ("invalid print command!\n");
						}		
					}
				}
			}
			else if (ch== 'q' || ch== 'Q')
			{
				
				break;
			}
			else if (ch!= ' ' && ch!= '\t' && ch!= '\n')
			{
				
				printf ("invalid command!\n");
			}
	}
}


