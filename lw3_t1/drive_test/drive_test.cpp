#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../drive/car.h"

TEST_CASE("Test car class instance creation")
{
	car car;

	/* Проверяем, что при создании машины её двигатель выключен, скорость равна 0, она не двигается и стоит на нейтральной передаче */
	CHECK_FALSE(car.getEngineCondition());
	CHECK( (car.getSpeed() == 0) );
	CHECK(car.getDirection() == "STAND STILL");
	CHECK(car.getGear() == "NEUTRAL");
}

TEST_CASE("Car engine starting test")
{
	car car;

	/* Включаем двигатель и проверяем, запустился ли он*/
	CHECK(car.TurnOnEngine());
	CHECK(car.getEngineCondition() );

	/* Проверяем, останется ли машина неподвижной, будет иметь нулевую скорость и стоять на нейтральной передаче после включения двигателя */
	CHECK(car.getSpeed() == 0);
	CHECK(car.getDirection() == "STAND STILL");
	CHECK(car.getGear() == "NEUTRAL");

	/* Проверяем, можно ли включить двигатель у автомобиля, если он уже запущен */
	CHECK(car.TurnOnEngine());
}

TEST_CASE("Car speed setting test")
{
	car car;

	/* Проверяем, можно ли развить какую-либо скорость при выключенном двигателе (нельзя)*/
	CHECK(!car.SetSpeed(20));

	car.TurnOnEngine();

	/* Переключаем передачу на заднюю и проверяем, можно ли достигнуть скорости, находящиеся и не находящиеся в диапазоне передачи */
	car.SetGear(-1);
	CHECK(car.SetSpeed(20));
	CHECK(!car.SetSpeed(21));
	CHECK(car.SetSpeed(0));

	car.SetGear(0);

	/* Аналогично протестируем достижение скоростей на других передачах */
	car.SetGear(1);
	CHECK(car.SetSpeed(30));
	CHECK(!car.SetSpeed(31));

	car.SetGear(2);
	CHECK(!car.SetSpeed(19));
	CHECK(car.SetSpeed(50));
	CHECK(!car.SetSpeed(51));

	car.SetGear(3);
	CHECK(!car.SetSpeed(29));
	CHECK(car.SetSpeed(60));
	CHECK(!car.SetSpeed(61));

	car.SetGear(4);
	CHECK(!car.SetSpeed(39));
	CHECK(car.SetSpeed(60));
	CHECK(!car.SetSpeed(61));

	car.SetGear(5);
	CHECK(!car.SetSpeed(49));
	CHECK(car.SetSpeed(120));
	CHECK(!car.SetSpeed(151));

	/* Проверяем, можно ли развить скорость, находясь на нейтральной передаче (нельзя), или уменьшить скорость (можно) */
	car.SetGear(0);
	CHECK(!car.SetSpeed(150));
	CHECK(car.SetSpeed(100));
	CHECK(car.SetSpeed(0));
}

TEST_CASE("Car gear switching test")
{
	car car;

	/* Проверяем, можно ли переключиться на нейтральную передачу (можно) или на любую другую передачу (нельзя) при выключенном двигателе */
	CHECK(car.SetGear(0));
	CHECK(!car.SetGear(1));

	car.TurnOnEngine();

	/* Проверяем, можно ли переключиться на заднюю передачу */
	CHECK(car.SetGear(-1));
	car.SetSpeed(20);

	/* Проверяем, можно ли переключиться с задней передачи на первую при ненулевой скорости (нельзя) */
	CHECK(!car.SetGear(1));

	CHECK(car.SetGear(0));

	/* Проверяем, можно ли переключиться с нейтральной передачи на первую, если машина еще катится назад по инерции (нельзя) */
	CHECK(!car.SetGear(1));

	car.SetSpeed(0);

	/* Проверяем, можно ли переключиться на первую передачу */
	CHECK(car.SetGear(1));

	/* Проверяем, можно ли переключиться на заднюю передачу с первой при нулевой скорости */
	CHECK(car.SetGear(-1));

	/* Проверяем, можно ли переключиться на первую передачу с задней при нулевой скорости */
	CHECK(car.SetGear(1));

	/* Проверяем переключения передач на возможных и невозможных для этого скоростях */
	CHECK(!car.SetGear(2));
	CHECK(car.SetSpeed(25));
	CHECK(car.SetGear(2));

	/* Проверяем, можно ли переключить передачу на нейтральную*/
	CHECK(car.SetGear(0));

	/* Устанавливаем прежнюю передачу и проверяем, не изменилась ли скорость */
	car.SetGear(2);
	CHECK(car.getSpeed() == 25);

	car.SetSpeed(35);
	CHECK(car.SetGear(3));
	CHECK(!car.SetGear(1));
	CHECK(!car.SetGear(4));

	car.SetSpeed(55);
	CHECK(car.SetGear(4));
	CHECK(!car.SetGear(2));

	car.SetSpeed(90);
	CHECK(car.SetGear(5));
	CHECK(car.SetGear(3));

	/* Проверяем, можно ли включить передачу, больше чем пятую (нельзя) */
	CHECK(!car.SetGear(6));
}

TEST_CASE("Car engine stoping test")
{
	car car;

	/* Проверяем, можно ли выключить двигатель, если он не был включенным */
	CHECK(car.TurnOffEngine());

	car.TurnOnEngine();

	/* Проверяем, можно ли выключить двигатель, если он был включенным */
	CHECK(car.TurnOffEngine());
	CHECK_FALSE(car.getEngineCondition());

	/* Проверяем, что другие свойства машины не изменились от начальных */
	CHECK(car.getSpeed() == 0);
	CHECK(car.getDirection() == "STAND STILL");
	CHECK(car.getGear() == "NEUTRAL");

	/* Проверяем, можно ли выключить двигатель при ненулевой скорости и не на нейтральной передаче (нельзя) */
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(25);
	CHECK(!car.TurnOffEngine());
}

TEST_CASE("Car direction switching test")
{
	car car;

	car.TurnOnEngine();

	/* При переключении на заднюю передачу, но без разгона, машина остается в стоячем положении */
	car.SetGear(-1);
	CHECK(car.getDirection() == "STAND STILL");

	/* При развитии скорости на задней передаче машины едет назад*/
	car.SetSpeed(20);
	CHECK(car.getDirection() == "BACKWARD");

	/* Переключаемся на первую передачу */
	car.SetSpeed(0);
	car.SetGear(1);

	/* При разгоне  машина едет вперед */
	car.SetSpeed(30);
	CHECK(car.getDirection() == "FORWARD");
}