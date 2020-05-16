/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    player.Update(wnd.kbd);
    if (wnd.mouse.RightIsPressed())
    {
        missle.Init(player.getX(),
                    player.getY(),
                    0,
                    255,
                    255,
                    10,
                    10,
                    10,
                    wnd.mouse.GetPosX(),
                    wnd.mouse.GetPosY());
    }
    if (missle.active) missle.Update();
    if (enemy.isColliding(missle) && missle.active)
    {
        enemy.Die();
        missle.Destroy();
    }
    if (enemy.isAlive) enemy.Update(player);
    if (!enemy.isAlive) 
    {
        if (getRandomNumber(0, enemy.spawnChance) == 73)
        {
            enemy.Init();
        }
    }
}

void Game::ComposeFrame()
{
    //drawBg(gfx);
    if (enemy.isAlive) enemy.Draw(gfx);
    if (missle.active) missle.Draw(gfx);
    player.Draw(gfx);
}

void Game::drawBg(Graphics& gfx)
{
    for (int yLoop = 0; yLoop < gfx.ScreenHeight; yLoop++)
    {
        for (int xLoop = 0; xLoop < gfx.ScreenWidth; xLoop++)
        {
            gfx.PutPixel(xLoop, yLoop, 100, 100, 100);
        }
    }
}