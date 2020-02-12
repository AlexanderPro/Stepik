/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

public class Robot {
    private int x;
    private int y;
    private Direction direction;

    public Robot() {
        this(0, 0, Direction.UP);
    }

    public Robot(int x, int y, Direction direction) {
        this.x = x;
        this.y = y;
        this.direction = direction;
    }

    public Direction getDirection() {
        return direction;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void turnLeft() {
        switch (direction) {
            case UP:
                direction = Direction.LEFT;
                break;
            case LEFT:
                direction = Direction.DOWN;
                break;
            case DOWN:
                direction = Direction.RIGHT;
                break;
            case RIGHT:
                direction = Direction.UP;
                break;
        }
    }

    public void turnRight() {
        switch (direction) {
            case UP:
                direction = Direction.RIGHT;
                break;
            case RIGHT:
                direction = Direction.DOWN;
                break;
            case DOWN:
                direction = Direction.LEFT;
                break;
            case LEFT:
                direction = Direction.UP;
                break;
        }
    }

    public void stepForward() {
        if (direction == Direction.UP) {
            y++;
        } else if (direction == Direction.RIGHT) {
            x++;
        } else if (direction == Direction.DOWN && y > 0) {
            y--;
        } else if (direction == Direction.LEFT && x > 0) {
            x--;
        }
    }

    public static void moveRobot(Robot robot, int toX, int toY) {
        if (toX > robot.getX()) {
            setDirection(robot, Direction.RIGHT);
            stepsForward(robot, toX - robot.getX());
        }

        if (toX < robot.getX()) {
            setDirection(robot, Direction.LEFT);
            stepsForward(robot, robot.getX() - toX);
        }

        if (toY > robot.getY()) {
            setDirection(robot, Direction.UP);
            stepsForward(robot, toY - robot.getY());
        }

        if (toY < robot.getY()) {
            setDirection(robot, Direction.DOWN);
            stepsForward(robot, robot.getY() - toY);
        }
    }
    
    public static void moveRobot(RobotConnectionManager robotConnectionManager, int toX, int toY) {
        int attempts = 0;

        while (true) {
            attempts++;
            if (attempts > 3) {
                throw new RobotConnectionException("Attempts > 3");
            }

            RobotConnection connection = null;
            try {
                // Установка соединения
                connection = robotConnectionManager.getConnection();
                connection.moveRobotTo(toX, toY);
                return;

            } catch (RobotConnectionException e) {
                // Попытаемся снова подключиться
                continue;

            } finally {
                // С try-с-ресурсами что-то не проходит
                if (connection != null) {
                    try {
                        // close тоже может выкинуть исключение и в тестах это проверяется
                        connection.close();
                    } catch (Throwable e) {

                    }
                }
            }
        }        
    }

    private static void setDirection(Robot robot, Direction direction) {
        while (robot.getDirection() != direction) {
            robot.turnRight();
        }
    }

    private static void stepsForward(Robot robot, int stepsNumber) {
        for (int i = 1; i <= stepsNumber; i++) {
            robot.stepForward();
        }
    }
}

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
}