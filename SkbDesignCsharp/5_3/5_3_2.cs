using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance.MapObjects
{
    public interface IOwnable
    {
        int Owner { get; set; }
    }

    public interface ITreasurable
    {
        Treasure Treasure { get; set; }
    }

    public interface IMillitary
    {
        Army Army { get; set; }
    }
    
    public class Dwelling : IOwnable
    {
        public int Owner { get; set; }
    }

    public class Mine : IOwnable, IMillitary, ITreasurable
    {
        public int Owner { get; set; }
        public Army Army { get; set; }
        public Treasure Treasure { get; set; }
    }

    public class Creeps : IMillitary, ITreasurable
    {
        public Army Army { get; set; }
        public Treasure Treasure { get; set; }
    }

    public class Wolfs : IMillitary
    {
        public Army Army { get; set; }
    }

    public class ResourcePile : ITreasurable
    {
        public Treasure Treasure { get; set; }
    }

    public static class Interaction
    {
        public static void Make(Player player, object mapObject)
        {
            if (mapObject is Mine)
            {
                if (player.CanBeat(((Mine)mapObject).Army))
                {
                    ((Mine)mapObject).Owner = player.Id;
                    player.Consume(((Mine)mapObject).Treasure);
                }
                else player.Die();
                return;
            }
            if (mapObject is IOwnable)
            {
                ((IOwnable)mapObject).Owner = player.Id;
                return;
            }
            if (mapObject is Creeps)
            {
                if (player.CanBeat(((Creeps)mapObject).Army))
                    player.Consume(((Creeps)mapObject).Treasure);
                else
                    player.Die();
                return;
            }
            if (mapObject is ITreasurable)
            {
                player.Consume(((ITreasurable)mapObject).Treasure);
                return;
            }
            if (mapObject is IMillitary)
            {
                if (!player.CanBeat(((IMillitary)mapObject).Army))
                    player.Die();
            }
        }
    }
}