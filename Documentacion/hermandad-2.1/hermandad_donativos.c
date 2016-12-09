/*This is some code I had been wanting to write since my early days and
just kept forgetting about. Then I came accross a snippet on this site 
with no header 'http://www.mudmagic.com/codes/dl/405' and it gave my idea
back. So after a little work I have put it together, so here it is*/

/*in merc.h under pc_data*/
long   guild_marks;

/*save.c under fwrite_char*/
    if (ch->pcdata->guild_marks > 0)
      fprintf( fp, "Guild_Marks %ld\n",ch->pcdata->guild_marks);
    else
      fprintf( fp, "Guild_Marks %d\n", 0);

/*save.c under fread_char*/
KEY ("Guild_Marks",   ch->pcdata->guild_marks,  fread_number( fp ) );

/*save.c in load_char_obj*/
ch->pcdata->guild_marks	= 0;

/*db.c under clear_char*/
ch->pcdata->guild_marks	= 0;

/*recycle.c under free_char*/
        if ( ch->pcdata )
    {       
	ch->pcdata->guild_marks = 0;
    	free_pcdata(ch->pcdata);
    }

/*act_obj.c in do_get, under the following*/
/* 'get ... container' */
          /*if ( !str_cmp ( arg2, "all" ) ||
               !str_prefix ( "all.", arg2 ) )
          {
               send_to_char ( "You can't do that.\n\r", ch );
               return;
          }*/
          
          if ( (container = get_obj_list(ch, "guild box", ch->in_room->contents)))
          {
               send_to_char("You can only borrow from a guild box.\n\r",ch);
               return;
          }
/*Ghreth's donation code, 04/29/06*/
void do_donate( CHAR_DATA *ch, char *argument)
{
   OBJ_DATA *guild_box;
   OBJ_DATA *obj;
   char arg[MAX_INPUT_LENGTH];
   char buf[MAX_STRING_LENGTH];
   int amount;
   
   argument = one_argument(argument, arg);

   if (IS_NPC(ch))
    {
	send_to_char("NPC's dont donate.\n\r", ch);
	return;
    }
   
   if (arg[0] == '\0' )
   {
      send_to_char("Donate what?\n\r",ch);
      return;
   }
   
   if ( (guild_box = get_obj_list(ch, "guild box", ch->in_room->contents)) == NULL)
   {
      send_to_char("There doesnt seem to be a guild box here.\n\r",ch);
      return;
   }

   if ( (obj = get_obj_carry (ch, arg)) == NULL)
   {
      send_to_char("You do not have that.\n\r",ch);
      return;
   }
   else
   {
      if (!can_drop_obj(ch, obj) && ch->level < 52)
      {
         send_to_char("You cant seem to let it go.\n\r",ch);
         return;
      }
      if ((obj->item_type == ITEM_CORPSE_NPC) 
      ||  (obj->item_type == ITEM_CORPSE_PC))
      {
         send_to_char("You cannot donate that.\n\r",ch);
         return;
      }
      if (obj->timer > 0)
      {
         send_to_char("You cannot donate that.\n\r",ch);
         return;
      }
         act("$n donates {Y$p{x to the guild box.",ch,obj,NULL,TO_ROOM);
         act("You donate {Y$p{x to the guild box.",ch,obj,NULL,TO_CHAR);
         
      if ((!IS_OBJ_STAT(obj ,ITEM_ANTI_EVIL) && IS_EVIL(ch)) 
      ||  (!IS_OBJ_STAT(obj ,ITEM_ANTI_GOOD) && IS_GOOD(ch)) 
      ||    IS_NEUTRAL(ch)) 
         
         if (obj->level > 0)
         {
            amount = UMAX(1, obj->level/7);
            if (amount == 1)
            {
               xprintf(buf, "You receive one guild mark for your item.\n\r");
               send_to_char(buf,ch);
            }
            else
            {
               xprintf( buf, "You receive %ld guild marks for your item.\n\r",amount);
               send_to_char(buf,ch);
            }
             
            ch->pcdata->guild_marks += amount;
         }
     
         obj_from_char(obj);
         obj_to_obj(obj, guild_box);
         return;
     }
}

/*Ghreth's donation code, 04/29/06*/
void do_borrow( CHAR_DATA *ch, char *argument)
{
   OBJ_DATA *guild_box;
   OBJ_DATA *obj;
   char arg[MAX_INPUT_LENGTH];
   char buf[MAX_STRING_LENGTH];
   int amount;
   
   argument = one_argument(argument, arg);

        if (IS_NPC(ch))
    {
	send_to_char("NPC's dont borrow.\n\r", ch);
	return;
    }
   
   if (arg[0] == '\0' )
   {
      send_to_char("Borrow what?\n\r",ch);
      return;
   }
   
   if ( (guild_box = get_obj_list(ch, "guild box", ch->in_room->contents)) == NULL)
   {
      send_to_char("There doesnt seem to be a guild box here.\n\r",ch);
      return;
   }
   
   obj = get_obj_list ( ch, arg, guild_box->contains );
   if ( obj == NULL )
   {
       send_to_char("I see nothing like that in the guild box.\n\r",ch);
       return;
   }
         
      act("$n borrows {Y$p{x from the guild box.",ch,obj,NULL,TO_ROOM);
      act("You borrow {Y$p{x from the guild box.",ch,obj,NULL,TO_CHAR);
      
      if ((!IS_OBJ_STAT(obj ,ITEM_ANTI_EVIL) && IS_EVIL(ch)) 
      ||  (!IS_OBJ_STAT(obj ,ITEM_ANTI_GOOD) && IS_GOOD(ch)) 
      ||    IS_NEUTRAL(ch)) 
         
         if (obj->level > 0)
         {
            amount = UMAX(1, obj->level/7);
            if ( ch->pcdata->guild_marks < amount )
         {
	       send_to_char( "You do not possess enough guild marks to borrow that.\n\r", ch );
	       return;
         }
            if (amount == 1)              
         {
               xprintf(buf, "You lose one guild mark for your item.\n\r");
               send_to_char(buf,ch);
         }
            else
         {
               xprintf( buf, "You lose %ld guild marks for your item.\n\r",amount);
               send_to_char(buf,ch);
         }
             
            ch->pcdata->guild_marks -= amount;
         }
    
         obj_to_char(obj, ch);
         return;
}
