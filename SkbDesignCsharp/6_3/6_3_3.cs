using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Generics.Robots
{
    public abstract class RobotAI<T> where T : IMoveCommand 
    {
        public abstract T GetCommand();
    }

    public class ShooterAI : RobotAI<IMoveCommand>
    {
        int counter = 1;

        public override IMoveCommand GetCommand()
        {
            return ShooterCommand.ForCounter(counter++);
        }
    }

    public class BuilderAI : RobotAI<IMoveCommand>
    {
        int counter = 1;
        public override IMoveCommand GetCommand()
        {
            return BuilderCommand.ForCounter(counter++);
        }
    }

    public abstract class Device<T> where T : IMoveCommand
    {
        public abstract string ExecuteCommand(T command);
    }

    public class Mover : Device<IMoveCommand>
    {
        public override string ExecuteCommand(IMoveCommand _command)
        {
            var command = _command as IMoveCommand;
            if (command == null)
                throw new ArgumentException();
            return $"MOV {command.Destination.X}, {command.Destination.Y}";
        }
    }



    public class Robot
    {
        RobotAI<IMoveCommand> ai;
        Device<IMoveCommand>  device;

        public Robot(RobotAI<IMoveCommand> ai, Device<IMoveCommand> executor)
        {
            this.ai = ai;
            this.device = executor;
        }

        public IEnumerable<string> Start(int steps)
        {
             for (int i=0;i<steps;i++)
             {
                 var command = ai.GetCommand();
                 if (command == null)
                     break;
                 yield return device.ExecuteCommand(command);
             }

        }

        public static Robot Create(RobotAI<IMoveCommand> ai, Device<IMoveCommand> executor)
        {
            return new Robot(ai, executor);
        }
    }
}