#include "AppClass.h"
void Application::InitVariables(void)
{
	//How much we are drawing
	m_uMeshCount = 46;
	for (int i = 0; i < m_uMeshCount; ++i)
	{
		MyMesh* pMesh = new MyMesh();
		m_pMeshList.push_back(pMesh);
		m_pMeshList[i]->GenerateCube(1.0f, C_CYAN);
	}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();

	matrix4 m4Scale = glm::scale(vector3(0.5f, 0.5f, 0.5f));
	static float value = -25.0f;

	m4View *= m4Scale;
	int i = 0;


	//Taken from C11 uses value to move the x value making all cubes move to the right
	matrix4 m4Position = glm::translate(vector3(value, 0.0f, 0.0f));
	value += 0.1f;

	//1st row
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 7.0f, 0.0f)));
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 7.0f, 0.0f)));
	i++;

	//2nd row
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 6.0f, 0.0f)));
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 6.0f, 0.0f)));
	i++;

	//3rd row
	for (uint count = 2; count < 9; count++)
	{
		m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(count, 5.0f, 0.0f)));
		i++;
	}

	//4th row
	for (uint count = 1; count < 10; count++)
	{
		if (count == 3 || count == 7) { count++; }
		m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(count, 4.0f, 0.0f)));
		i++;
	}

	//5th row
	for (uint count = 0; count < 11; count++)
	{
		m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(count, 3.0f, 0.0f)));
		i++;
	}

	//6th row
	for (uint count = 0; count < 11; count++)
	{
		if (count == 1 || count == 9) { count++; }
		m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(count, 2.0f, 0.0f)));
		i++;
	}

	//7th row
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(0.0f, 1.0f, 0.0f)));
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 1.0f, 0.0f)));
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 1.0f, 0.0f)));
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(10.0f, 1.0f, 0.0f)));
	i++;

	//8th row
	for (uint count = 3; count < 8; count++)
	{
		if (count == 5) { count++; }
		m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(count, 0.0f, 0.0f)));
		i++;
	}



	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//release GUI
	ShutdownGUI();
}