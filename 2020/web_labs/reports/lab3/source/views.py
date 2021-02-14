from rest_framework import status
from rest_framework.decorators import api_view
from rest_framework.response import Response
from things.models import Thing
from things.serializers import ThingSerializer

@api_view(['GET', 'POST'])
def things_list(request):
    if request.method == 'GET':
        things = Thing.objects.all()
        serializer = ThingSerializer(things, many=True)
        return Response(serializer.data)

    elif request.method == 'POST':
        serializer = ThingSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)